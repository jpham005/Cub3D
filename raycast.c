/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:51:47 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 15:07:25 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static void	set_x_dependant_info(t_cast_info *info, int x)
{
	info->camera.x = 2 * x / (double) WINDOW_WIDTH - 1;
	set_ray_vector(info);
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

static void	put_buffer_pixel(
	t_context *context, int buffer[WINDOW_HEIGHT][WINDOW_WIDTH]
)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			ft_pixel_put(context->img, j, i, buffer[i][j]);
			++j;
		}
		++i;
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
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		set_x_dependant_info(&info, x);
		perform_dda(&info, context);
		calculate_texture(&info, x, context);
		++x;
	}
	put_buffer_pixel(context, info.buffer);
}
