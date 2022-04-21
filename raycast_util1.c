/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:21:50 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 13:32:27 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_buffer_default(
	int buffer[WINDOW_HEIGHT][WINDOW_WIDTH], t_texture *texture
)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			buffer[y][x++] = texture->c;
		++y;
	}
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			buffer[y][x++] = texture->f;
		++y;
	}
}

void	set_dir_vector(t_vector *dir, t_map_data pos_dir)
{
	dir->x = 0;
	dir->y = 0;
	if (pos_dir & POS_N)
		dir->y = -1;
	else if (pos_dir & POS_S)
		dir->y = 1;
	else if (pos_dir & POS_E)
		dir->x = 1;
	else
		dir->x = -1;
}

void	set_plane_vector(t_vector *plane, t_map_data pos_dir)
{
	plane->x = 0;
	plane->y = 0;
	if (pos_dir & POS_N)
		plane->x = 0.66;
	else if (pos_dir & POS_S)
		plane->x = -0.66;
	else if (pos_dir & POS_E)
		plane->y = 0.66;
	else
		plane->y = -0.66;
}

void	set_ray_vector(t_cast_info *info)
{
	info->ray.x = info->dir.x + info->plane.x * info->camera.x;
	info->ray.y = info->dir.y + info->plane.y * info->camera.x;
}
