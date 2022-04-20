/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:51:47 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 23:07:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_x_dependant_info(t_cast_info *info)
{
	info->camera.x = 2 * x / (double) WINDOW_WIDTH - 1;
	set_ray_vector(&info);
	init_vector(&(info->map), (int) info->pos.x, (int) info->pos.y);
	set_delta_dist(info);
	set_side_dist(info);
}

static void	perform_dda(t_cast_info *info, t_context *context)
{
	info->hit = 0;
	while (!(info->hit))
	{
		if (info->side.x < info->side.y)
		{
			info->side.x += info->delta.x;
			info->map.x += info->step.x;
			info->hit_side = X_SIDE;
		}
		else
		{
			info->side.y += info->delta.y;
			info->map.y += info->step.y;
			info->hit_side = Y_SIDE;
		}
		if (context->map->grid[(int) info->map.y][(int) info->map.x] & WALL)
			info->hit = 1;
	}
}

void	cast_ray(t_context *context)
{
	t_cast_info	info;
	int			x;

	init_vector(&(info.pos), context->pos.x, context->pos.y);
	set_buffer_default(info.buffer, context->map->texture);
	set_dir_vector(&(info.dir), context->pos_dir);
	set_plane_vector(&(info.plane), context->pos_dir);
	while (x < WINDOW_WIDTH)
	{
		set_x_dependant_info(&info);
		perform_dda(&info, context);
		calc_texture(&info);
		++x;
	}
	print_buffer(info.buffer);
}
