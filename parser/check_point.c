/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:11:57 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 04:36:58 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_edge_point(size_t width, size_t height, size_t i, size_t j)
{
	return ((i == 0) || (i == height) || (j == 0) || (j == width));
}

static int	is_valid_point(t_map *map, size_t i, size_t j, t_map_data available)
{
	return (
		!is_edge_point(map->width, map->height, i, j)
		&& (map->grid[i - 1][j] & available)
		&& (map->grid[i + 1][j] & available)
		&& (map->grid[i][j - 1] & available)
		&& (map->grid[i][j + 1] & available)
	);
}

void	check_player_point(t_map *map, size_t i, size_t j, size_t *player_cnt)
{
	if (*player_cnt)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	*player_cnt |= 1;
	if (!is_valid_point(map, i, j, WALL | FIELD | DOOR))
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}

void	check_field_point(t_map *map, size_t i, size_t j)
{
	if (!is_valid_point(map, i, j, FIELD | WALL | PLAYER | DOOR))
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}

void	check_door_point(t_map *map, size_t i, size_t j)
{
	if (!is_valid_point(map, i, j, FIELD | WALL | PLAYER | DOOR))
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}