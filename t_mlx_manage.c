/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:51:45 by jaham             #+#    #+#             */
/*   Updated: 2022/04/19 15:43:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
void	test_print(t_map *map)
{
	int i = 0, j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
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

static t_img	*init_img(t_mlx_core *core)
{
	t_img	*ret;

	ret = ft_malloc(sizeof(t_img), 1);
	ret->img = mlx_new_image(core->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ret->addr = mlx_get_data_addr(ret->img, &(ret->bits_per_pixel), \
										&(ret->line_length), &(ret->endian));
	return (ret);
}

static t_mlx_core	*init_mlx(void)
{
	t_mlx_core	*ret;

	ret = ft_malloc(sizeof(t_mlx_core), 1);
	ret->mlx = mlx_init();
	if (!ret->mlx)
		exit_message(MLX_ERR_MESSAGE, EXIT_FATAL);
	ret->window = mlx_new_window(ret->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	if (!ret->window)
		exit_message(MLX_ERR_MESSAGE, EXIT_FATAL);
	return (ret);
}

static void	find_pos(t_context *context)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < context->map->height)
	{
		j = 0;
		while (j < context->map->width)
		{
			if (context->map->grid[i][j] & PLAYER)
			{
				context->pos.x = j + 0.5;
				context->pos.y = i + 0.5;
				context->pos_dir = context->map->grid[i][j];
				return ;
			}
			++j;
		}
		++i;
	}
}

void	init_context(t_context *context, char *argv)
{
	context->map = init_map();
	parse_map(context->map, argv);
	// test_print(context->map);
	find_pos(context);
	context->core = init_mlx();
	context->img = init_img(context->core);
}
