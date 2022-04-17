/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:45:52 by jaham             #+#    #+#             */
/*   Updated: 2022/04/17 14:16:07 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_valid_grid_point(
	t_map *map, size_t i, size_t j, size_t *player_cnt
)
{
	if (map->grid[i][j] & FIELD)
		check_field_point(map, i, j);
	if (map->grid[i][j] & PLAYER)
		check_player_point(map, i, j, player_cnt);
}

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
}
