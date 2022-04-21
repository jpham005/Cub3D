/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:10:13 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 15:19:07 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	calculate_wall_x(t_cast_info *info)
{
	if (info->hit_side == X_SIDE)
	{
		info->perp = (info->map.x - info->pos.x + (1 - info->step.x) / 2) \
																/ info->ray.x;
		info->wall.x = info->pos.y + info->perp * info->ray.y;
	}
	else
	{
		info->perp = (info->map.y - info->pos.y + (1 - info->step.y) / 2) \
																/ info->ray.y;
		info->wall.x = info->pos.x + info->perp * info->ray.x;
	}
	info->wall.x -= floor(info->wall.x);
}

void	set_tex_x(t_cast_info *info)
{
	info->tex_x = (int)(info->wall.x * (double) TEX_WIDTH);
	if (is_flipped(info))
		info->tex_x = (TEX_WIDTH - 1) - info->tex_x;
}

void	set_draw_line(t_cast_info *info)
{
	info->line_len = (int)(WINDOW_HEIGHT / info->perp);
	info->draw_start = -(info->line_len) / 2 + WINDOW_HEIGHT / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_len / 2 + WINDOW_HEIGHT / 2;
	if (info->draw_end >= WINDOW_HEIGHT)
		info->draw_end = WINDOW_HEIGHT - 1;
	info->tex_step = 1.0 * TEX_HEIGHT / info->line_len;
	info->tex_pos = (info->draw_start - WINDOW_HEIGHT / 2 + \
										info->line_len / 2) * info->tex_step;
}

static int	*choose_curr_texture(t_cast_info *info, t_context *context)
{
	int	*ret;

	if (info->hit_side == 0)
	{
		if (info->pos.x < info->map.x)
			ret = context->texture[TEX_EAST];
		else
			ret = context->texture[TEX_WEST];
	}
	if (info->hit_side == 1)
	{
		if (info->pos.y < info->map.y)
			ret = context->texture[TEX_NORTH];
		else
			ret = context->texture[TEX_SOUTH];
	}
	return (ret);
}

void	calculate_texture(t_cast_info *info, int x, t_context *context)
{
	int	*curr_texture;
	int	y;
	int	color;

	calculate_wall_x(info);
	set_tex_x(info);
	set_draw_line(info);
	y = info->draw_start;
	while (y <= info->draw_end)
	{
		info->tex_y = (int) info->tex_pos & (TEX_HEIGHT - 1);
		info->tex_pos += info->tex_step;
		curr_texture = choose_curr_texture(info, context);
		color = curr_texture[TEX_HEIGHT * info->tex_y + info->tex_x];
		if (info->hit_side == Y_SIDE)
			color = (color >> 1) & 0x7f7f7f;
		info->buffer[y][x] = color;
		++y;
	}
}
