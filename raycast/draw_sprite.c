/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:09:03 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 18:17:31 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>
void	draw_sprite(t_context *context, t_cast_info *info, double z_buffer[WINDOW_WIDTH])
{
	t_sprite	*sprite;

	if (!context->map->sprite_cnt)
		return ;
	sort_sprite(&(context->pos), context->map->sprites);
	sprite = context->map->sprites;
	for (size_t i = 0; i < context->map->sprite_cnt; ++i)
	{
		double	sprite_x = sprite->x - context->pos.x + 0.5;
		double	sprite_y = sprite->y - context->pos.y + 0.5;

		double	inv_det = 1.0 / (info->plane.x * info->dir.y - info->dir.x * info->plane.y);

		double	transform_x = inv_det * (info->dir.y * sprite_x - info->dir.x * sprite_y);
		double	transform_y = inv_det * (-info->plane.y * sprite_x + info->plane.x * sprite_y);
	
		int	sprite_screen_x = (int)((WINDOW_WIDTH / 2) * (1 + transform_x / transform_y));

		int	sprite_height = abs((int)(WINDOW_HEIGHT / transform_y));
		
		int	draw_start_y = -sprite_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		
		int	draw_end_y = sprite_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_end_y >= WINDOW_HEIGHT)
			draw_end_y = WINDOW_HEIGHT - 1;
		
		int	sprite_width = abs((int)(WINDOW_HEIGHT / transform_y));
		int	draw_start_x = -sprite_width / 2 + sprite_screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;

		int	draw_end_x = sprite_width / 2 + sprite_screen_x;
		if (draw_end_x >= WINDOW_WIDTH)
			draw_end_x = WINDOW_WIDTH - 1;

		for (int j = draw_start_x; j < draw_end_x; ++j)
		{
			int	tex_x = (int)(256 * (j - (-sprite_width / 2 + sprite_screen_x)) * TEX_WIDTH / sprite_width) / 256;
			(void) z_buffer;
			if (transform_y > 0 && j > 0 && j < WINDOW_WIDTH && transform_y < z_buffer[j])
			{
				for (int y = draw_start_y; y < draw_end_y; ++y)
				{
					int d = y * 256 - WINDOW_HEIGHT * 128 + sprite_height * 128;
					int	tex_y = ((d * TEX_HEIGHT) / sprite_height) / 256;
					int	color = context->texture[TEX_SPRITE_1][TEX_WIDTH * tex_y + tex_x];
					if ((color & 0x00FFFFFF) != 0)
						info->buffer[y][j] = color;
				}
			}
		}
		sprite = sprite->next;
	}
}
