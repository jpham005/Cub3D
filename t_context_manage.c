/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_context_manage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:11:48 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 20:13:09 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_img_texture(t_context *context)
{
	context->texture[TEX_NORTH] = load_img(context, TEX_NORTH);
	context->texture[TEX_WEST] = load_img(context, TEX_WEST);
	context->texture[TEX_SOUTH] = load_img(context, TEX_SOUTH);
	context->texture[TEX_EAST] = load_img(context, TEX_EAST);
	
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
	set_img_texture(context);
	find_pos(context);
	context->core = init_mlx();
	context->img = init_img(context->core);
}
