/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:47:24 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 14:43:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int	get_minimap_color(
	t_context *context, t_minimap *minimap
)
{
	if (is_outrange(context, minimap))
		return (BACKGROUND_COLOR);
	if (context->map->grid[minimap->curr_y][minimap->curr_x] & (FIELD | PLAYER))
		return (FOREGROUND_COLOR);
	if (context->map->grid[minimap->curr_y][minimap->curr_x] & DOOR)
		return (DOOR_COLOR);
	if (context->map->grid[minimap->curr_y][minimap->curr_x] & SPRITE)
		return (SPRITE_COLOR);
	return (BACKGROUND_COLOR);
}

static void	set_next_step(t_minimap *minimap, char axis)
{
	if (axis == 'x')
	{
		++(minimap->curr_x);
		minimap->curr_step_x += minimap->step_x;
	}
	else
	{
		++(minimap->curr_y);
		minimap->curr_step_y += minimap->step_y;
	}
}

void	draw_minimap_wall(t_context *context, t_minimap *minimap)
{
	int			x;
	int			y;
	int			color;

	set_step_xy(context, minimap);
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		minimap->curr_x = 0;
		minimap->curr_step_x = minimap->step_x;
		while (x < MINIMAP_WIDTH)
		{
			color = get_minimap_color(context, minimap);
			ft_pixel_put(context->minimap, x, y, color);
			if (++x >= minimap->curr_step_x)
				set_next_step(minimap, 'x');
		}
		if (++y >= minimap->curr_step_y)
			set_next_step(minimap, 'y');
	}
}
