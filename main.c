/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:38:28 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 14:56:37 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "cub3d.h"
#include <stdio.h>

void	test_print(t_map *map)
{
	int i = 0, j = 0;
	while (i < map->grid_height)
	{
		j = 0;
		while (j < map->grid_width)
		{
			if (map->grid[i][j] == SPACE)
				printf(" ");
			else if (map->grid[i][j] == WALL)
				printf("%d", 1);
			else if (map->grid[i][j] & PLAYER)
				printf("P");
			else if (map->grid[i][j] & FIELD)
				printf("0");
			j++;
		}
		printf("\n");
		i++;
	}
	while (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		exit_message(ARG_ERR_MESSAGE, EXIT_FATAL);
	map = init_map();
	parse_map(map, argv[1]);
	// test_print(map);
	practice(map);
}
