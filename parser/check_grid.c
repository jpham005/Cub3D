/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:45:52 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 04:11:01 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
과정
1. 필드(0)인 경우
2. player(POS N S E W)인 경우
*/
static void	check_valid_grid_point(
	t_map *map, size_t i, size_t j, size_t *player_cnt
)
{
	if (map->grid[i][j] & FIELD)
		check_field_point(map, i, j);
	else if (map->grid[i][j] & PLAYER)
		check_player_point(map, i, j, player_cnt);
	else if (map->grid[i][j] & DOOR)
		check_door_point(map, i, j);
}

/*
프로토타입
t_map 검사

과정
1. 가로, 세로 길이만큼 순회하며 모든 점 검사
2. 플레이어 없으면 에러
*/
void	check_grid(t_map *map)
{
	size_t	player_cnt;
	size_t	i;
	size_t	j;

	player_cnt = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
			check_valid_grid_point(map, i, j++, &player_cnt);
		i++;
	}
	if (player_cnt != 1)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}
