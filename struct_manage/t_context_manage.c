/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_context_manage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:11:48 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 19:17:27 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static void	set_img_texture(t_context *context)
{
	context->texture[TEX_NORTH] = load_img(context, TEX_NORTH);
	context->texture[TEX_WEST] = load_img(context, TEX_WEST);
	context->texture[TEX_SOUTH] = load_img(context, TEX_SOUTH);
	context->texture[TEX_EAST] = load_img(context, TEX_EAST);
	context->texture[TEX_DOOR] = load_img(context, TEX_DOOR);
	context->texture[TEX_SPRITE_1] = load_img(context, TEX_SPRITE_1);
	context->texture[TEX_SPRITE_2] = load_img(context, TEX_SPRITE_2);
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

static t_map	*init_map(void)
{
	t_map	*ret;

	ret = ft_malloc(sizeof(t_map), 1);
	ft_memset(ret, 0, sizeof(t_map));
	return (ret);
}

void	init_context(t_context *context, char *argv)
{
	context->map = init_map();
	parse_map(context->map, argv);
	find_pos(context);
	context->core = init_mlx();
	context->img = init_img(context->core, WINDOW_WIDTH, WINDOW_HEIGHT);
	set_img_texture(context);
	context->minimap = init_img(context->core, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	context->curr_sprite = TEX_SPRITE_1;
	context->loop_cnt = 0;
}
