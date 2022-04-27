/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:09:03 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 21:27:37 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_sprite_color(
	t_sprite_info *sp_info, t_context *context, t_cast_info *ca_info, int j
)
{
	int	color;

	sp_info->y = sp_info->draw_start.y;
	while (sp_info->y < sp_info->draw_end.y)
	{
		sp_info->d = sp_info->y * 256 - WINDOW_HEIGHT * 128 \
										+ sp_info->sprite_height * 128;
		sp_info->tex_y = ((sp_info->d * TEX_HEIGHT) \
										/ sp_info->sprite_height) / 256;
		color = context->texture[context->curr_sprite][TEX_WIDTH \
									* sp_info->tex_y + sp_info->tex_x];
		if ((color & 0x00FFFFFF) != 0)
			ca_info->buffer[sp_info->y][j] = color;
		++(sp_info->y);
	}
}

static void	get_sprite_color(t_sprite_info *sp_info, t_context *context, \
						t_cast_info *ca_info, double z_buf[WINDOW_WIDTH])
{
	int	j;

	j = sp_info->draw_start.x;
	while (j < sp_info->draw_end.x)
	{
		sp_info->tex_x = (int)(256 * (j - (-sp_info->sprite_width / 2 + \
		sp_info->sprite_screen_x)) * TEX_WIDTH / sp_info->sprite_width) / 256;
		if (is_inrange_sprite(sp_info, z_buf, j))
			calculate_sprite_color(sp_info, context, ca_info, j);
		++j;
	}
}

void	draw_sprite(
	t_context *context, t_cast_info *cast_info, double z_buffer[WINDOW_WIDTH]
)
{
	t_sprite		*sprite;
	t_sprite_info	sprite_info;
	size_t			i;

	if (!context->map->sprite_cnt)
		return ;
	sort_sprite(&(context->pos), context->map->sprites);
	sprite = context->map->sprites;
	i = 0;
	while (i < context->map->sprite_cnt)
	{
		set_pos_sprite(&sprite_info, context, sprite);
		get_transform_pos(&sprite_info, cast_info);
		calculate_draw_point(&sprite_info);
		get_sprite_color(&sprite_info, context, cast_info, z_buffer);
		sprite = sprite->next;
		++i;
	}
}
