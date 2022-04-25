/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:24:09 by jaham             #+#    #+#             */
/*   Updated: 2022/04/25 20:57:47 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/*
프로토타입
line의 한 글자 c 받기, 어떤 데이터 타입인지 리턴

과정
1. if문으로 타입 매칭 시도
2. 매칭 실패 시, 맵 좌표에 잘못된 데이터가 있다는 의미, exit(1)
*/
static t_map_data	get_map_data(char c)
{
	if (c == ' ')
		return (SPACE);
	if (c == '0')
		return (FIELD);
	if (c == '1')
		return (WALL);
	if (c == '2')
		return (DOOR_CLOSED);
	if (c == '3')
		return (SPRITE);
	if (c == 'N')
		return (POS_N);
	if (c == 'S')
		return (POS_S);
	if (c == 'E')
		return (POS_E);
	if (c == 'W')
		return (POS_W);
	if (c == '\n')
		return (END_LINE);
	exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	return (WRONG);
}

/*
프로토타입
map_grid에 line 정보를 저장

과정
1. line의 한 글자를 grid의 list 한 노드로 추가
2. 개행이 아니라면 width 증가
3. width가 증가되지 않은 상태라면, 개행만 있었다는 의미이기 때문에, exit(1)
4. 새 줄의 width가 기존 줄들의 width 보다 크다면, width 갱신
*/
static void	add_line_to_grid_node(t_map_grid *map_grid, char *line)
{
	size_t		width;
	t_map_data	data;

	width = 0;
	while (*line)
	{
		data = get_map_data(*line);
		add_grid_node(&(map_grid->head), data);
		++line;
		if (data & SPRITE)
			++(map_grid->sprite_cnt);
		if (!(data & END_LINE))
			++width;
	}
	if (!width)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	if (width > map_grid->width)
		map_grid->width = width;
}

char	*set_to_content_line(int map_file)
{
	char	*ret;

	while (1)
	{
		ret = get_next_line(map_file);
		if (!ret)
			return (NULL);
		if (!ft_iseq(ret, "\n"))
			break ;
		ft_free((void **) &ret);
	}
	return (ret);
}

/*
프로토타입
map fd에서 읽고, t_map_grid에 담아서 해당 구조체를 반환

과정
1. 구조체 초기화
2. 텍스쳐 정보와 맵 좌표 정보 사이 개행을 생략, 맵 좌표 정보의 첫 줄로 세팅
3. 한 줄의 정보를 grid_node의 list에 담기
4. height를 증가 시키기
5. 다음 줄 받기 (NULL 일 경우, 다음 루프 첫 부분에서 종료)
*/
t_map_grid	*get_grid_list(int map_file)
{
	t_map_grid	*ret;
	char		*line;

	ret = init_map_grid();
	line = set_to_content_line(map_file);
	while (1)
	{
		if (!line)
			break ;
		add_line_to_grid_node(ret, line);
		++(ret->height);
		ft_free((void **) &line);
		line = get_next_line(map_file);
	}
	return (ret);
}
