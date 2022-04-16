/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:37:43 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 13:43:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player_point(t_map *map, size_t i, size_t j, size_t *player_cnt)
{
	const t_map_data	available = WALL | FIELD;

	if (*player_cnt)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	*player_cnt |= 1;
	if (
		!((map->grid[i - 1][j] & available)
		&& (map->grid[i + 1][j] & available)
		&& (map->grid[i][j - 1] & available)
		&& (map->grid[i][j + 1] & available))
	)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}
