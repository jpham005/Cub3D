/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:45:52 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 13:57:14 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
과정
마스크에 따라 검사
*/
static void	check_valid_grid_point(
	t_map *map, size_t i, size_t j, size_t *player_cnt
)
{
	if ((map->grid[i][j] & FIELD) && !is_valid_map_point(map, i, j, FIELD_MASK))
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	if ((map->grid[i][j] & DOOR) && !is_valid_map_point(map, i, j, DOOR_MASK))
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	if ((map->grid[i][j] & SPRITE) \
		&& !is_valid_map_point(map, i, j, SPRITE_MASK))
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	if (map->grid[i][j] & PLAYER)
		check_player_point(map, i, j, player_cnt);
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
