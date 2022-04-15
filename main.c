/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:38:28 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 22:48:35 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "cub3d.h"
#include <stdio.h>
// int	key_press_handler(int keycode, void *param)
// {
// 	(void) param;
// 	if (keycode == 53)
// 		exit(0);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		exit_message(NULL, ARG_ERR_MESSAGE, EXIT_FATAL);
	map = init_map();
	parse_map(map, argv[1]);
	int i = 0, j = 0;
	while (i < map->grid_height)
	{
		j = 0;
		while (j < map->grid_width)
		{
			printf("%d", map->grid[i][j++]);
		}
		printf("\n");
		i++;
	}
	while (1);
}
