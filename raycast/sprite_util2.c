/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:22:32 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 21:27:32 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static void	cut_edge_draw_point(t_sprite_info *info)
{
	if (info->draw_start.x < 0)
		info->draw_start.x = 0;
	if (info->draw_start.y < 0)
		info->draw_start.y = 0;
	if (info->draw_end.x >= WINDOW_WIDTH)
		info->draw_end.x = WINDOW_WIDTH - 1;
	if (info->draw_end.y >= WINDOW_HEIGHT)
		info->draw_end.y = WINDOW_HEIGHT - 1;
}

void	calculate_draw_point(t_sprite_info *info)
{
	info->sprite_screen_x = \
		(int)((WINDOW_WIDTH / 2) * (1 + info->transform.x / info->transform.y));
	info->sprite_height = abs((int)(WINDOW_HEIGHT / info->transform.y));
	info->draw_start.y = -info->sprite_height / 2 + WINDOW_HEIGHT / 2;
	info->draw_end.y = info->sprite_height / 2 + WINDOW_HEIGHT / 2;
	info->sprite_width = abs((int)(WINDOW_HEIGHT / info->transform.y));
	info->draw_start.x = -info->sprite_width / 2 + info->sprite_screen_x;
	info->draw_end.x = info->sprite_width / 2 + info->sprite_screen_x;
	cut_edge_draw_point(info);
}

int	is_inrange_sprite(
	t_sprite_info *sp_info, double z_buf[WINDOW_WIDTH], int j
)
{
	return (
		(sp_info->transform.y > 0)
		&& (j > 0)
		&& (j < WINDOW_WIDTH)
		&& (sp_info->transform.y < z_buf[j])
	);
}
