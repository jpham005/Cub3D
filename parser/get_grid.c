/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:22:56 by jaham             #+#    #+#             */
/*   Updated: 2022/04/17 14:16:07 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/*
프로토타입
grid 한 줄에 정보 저장, 전체 리스트 head에서 한 줄 만큼 읽기

과정
1. 개행 전 까지 정보 저장
2. width보다 인덱스 i가 작다면, 공백으로 채워 넣기
3. *head가 있다면, 그 자리는 개행 이므로 건너뛰기, 없다면 eof이므로 종료
*/
static void	put_single_line(int *grid, t_grid_node **head, size_t width)
{
	size_t	i;

	i = 0;
	while (*head && (*head)->data != END_LINE)
	{
		grid[i++] = (*head)->data;
		*head = (*head)->next;
	}
	while (i < width)
		grid[i++] = SPACE;
	if (*head)
		*head = (*head)->next;
}

/*
프로토타입
grid에 map_grid의 정보를 담기

과정
1. map_grid의 list의 첫 주소를 cp에 복사 후, 끝까지 순회 (head 자체 이용 시 누수 발생)
2. grid의 한 줄에 width만큼 할당
3. 해당 줄에 한 줄 만큼 순회하면서 저장, 이 때 cp는 함수 내부에서 한 줄 만큼 전진한 상태로 변경된다
*/
static void	put_grid_node(int **grid, t_map_grid *map_grid)
{
	t_grid_node	*cp;
	size_t		i;

	cp = map_grid->head;
	i = 0;
	while (cp)
	{
		grid[i] = ft_malloc(sizeof(int), map_grid->width);
		put_single_line(grid[i++], &cp, map_grid->width);
	}
}

static void	convert_grid_list(t_map *map, t_map_grid *map_grid)
{
	map->width = map_grid->width;
	map->height = map_grid->height;
	map->grid = ft_malloc(sizeof(int *), map_grid->height);
	put_grid_node(map->grid, map_grid);
}

/*
프로토타입
t_map에 데이터 저장, 읽는 파일의 fd 받기

과정
1. list 형태로 t_map_grid에 파싱 (가로, 세로 정보가 없기 때문)
2. 파싱 결과가 에러일 경우, exit(1) (가로, 세로가 0이고, head가 NULL인 상태)
2. 해당 list를 이중 포인터 형태로 바꾸고, 가로, 세로 정보를 저장
3. list 삭제
*/
void	get_grid(t_map *map, int map_file)
{
	t_map_grid	*map_grid_list;

	map_grid_list = get_grid_list(map_file);
	if (!map_grid_list->width)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	convert_grid_list(map, map_grid_list);
	del_map_grid(&map_grid_list);
}
