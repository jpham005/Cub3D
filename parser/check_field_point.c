/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_field_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:33:52 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 13:40:21 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_edge_point(size_t width, size_t height, size_t i, size_t j)
{
	return ((i == 0) || (i == height) || (j == 0) || (j == width));
}

static int	is_valid_field_point(t_map *map, size_t i, size_t j)
{
	const t_map_data	available = FIELD | WALL | PLAYER;

	return (
		(map->grid[i - 1][j] & available)
		&& (map->grid[i + 1][j] & available)
		&& (map->grid[i][j - 1] & available)
		&& (map->grid[i][j + 1] & available)
	);
}

void	check_field_point(t_map *map, size_t i, size_t j)
{
	if (
		is_edge_point(map->grid_width, map->grid_height, i, j)
		|| !is_valid_field_point(map, i, j)
	)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}
