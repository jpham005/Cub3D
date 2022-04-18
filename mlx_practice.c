/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_practice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:53:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/19 08:00:53 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int	is_move_keycode(int keycode)
{
	return (
		(keycode == KEY_A)
		|| (keycode == KEY_D)
		|| (keycode == KEY_W)
		|| (keycode == KEY_S)
	);
}

int	is_valid_point(double x, t_map *map)
{

}

void	move_pos(double x, double y, t_context *context)
{
	if (x && is_valid_point(context->pos.x + x, context->map))
		context->pos.x += x;
	if (y && is_valid_point(context->pos.y + x, context->map))
		context->pos.y += y;
}

void	handle_move_keycode(int keycode, t_context *context)
{
	if (keycode == KEY_A)
		move_pos(-MOVE_DIS, 0, context);
	if (keycode == KEY_D)
		move_pos(MOVE_DIS, 0, context);
	if (keycode == KEY_W)
		move_pos(0, -MOVE_DIS, context);
	if (keycode == KEY_S)
		move_pos(0, MOVE_DIS, context);
}

int	key_press_handler(int keycode, void *param)
{
	t_context	*context;

	context = (t_context *) param;
	if (keycode == KEY_ESC)
		exit(0);
	if (is_move_keycode(keycode))
		handle_move_keycode(keycode, context);
	return (0);
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

void	set_camera_vector(t_vector *camera, int x, t_vector *plane)
{
	camera->x = 0;
	camera->y = 0;
	if (x < WINDOW_WIDTH /2)
		camera->x = -1 / (WINDOW_WIDTH / 2 - x);
	else if (x == WINDOW_WIDTH / 2)
		camera->x = 0;
	else
		camera->x = 1 / (x - WINDOW_WIDTH / 2);
}

void	set_ray_vector(t_vector *ray, t_vector *dir, t_vector *plane, t_vector *camera)
{
	ray->x = dir->x + plane->x * camera->x;
	ray->y = dir->y + plane->y * camera->x;
}

void	set_delta_dist(t_vector *delta, t_vector *ray)
{
	delta->x = fabs(1 / ray->x);
	delta->y = fabs(1 / ray->y);
}

void	set_side_dist(t_vector *side, t_vector *step, t_vector *ray, t_vector *delta, t_vector *map, t_vector *pos)
{
	if (ray->x < 0)
	{
		step->x = -1;
		side->x = delta->x * (pos->x - map->x);
	}
	else
	{
		step->x = 1;
		side->x = delta->x * (map->x - pos->x + 1);
	}
	if (ray->y < 0)
	{
		step->y = -1;
		side->y = delta->y * (pos->y - map->y);
	}
	else
	{
		step->y = 1;
		side->y = delta->y * (map->y - pos->y + 1);
	}
}

void	practice(t_context *context)
{
	// ================================================= //
	// draw celling, floor
	for (size_t i = 0; i < WINDOW_HEIGHT / 2; i++)
	{
		for (size_t j = 0; j < WINDOW_WIDTH; j++)
			ft_pixel_put(context->img, j, i, context->map->texture->c);
	}
	for (size_t i = 0; i < WINDOW_HEIGHT / 2; i++)
	{
		for (size_t j = 0; j < WINDOW_WIDTH; j++)
			ft_pixel_put(context->img, j, i + WINDOW_HEIGHT / 2, context->map->texture->f);
	}
	// ================================================= //
	// cast single ray
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;

	pos.x = context->pos.x;
	pos.y = context->pos.y;
	set_dir_vector(&dir, context->pos_dir);
	set_plane_vector(&plane, context->pos_dir);

	t_vector	camera;
	t_vector	ray;
	t_vector	map;
	t_vector	side;
	t_vector	delta;
	t_vector	step;
	int			hit;
	int			hit_side;
	double		perp;
	int			line_len;
	int			h = WINDOW_HEIGHT;
	int			draw_start;
	int			draw_end;
	
	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		// set_camera_vector(&camera, x, &plane);
		camera.x = 2 * x / (double) WINDOW_WIDTH - 1;
		set_ray_vector(&ray, &dir, &plane, &camera);
		map.x = (int) pos.x;
		map.y = (int) pos.y;
		set_delta_dist(&delta, &ray);
		set_side_dist(&side, &step, &ray, &delta, &map, &pos);

		hit = 0;
		while (!hit)
		{
			if (side.x < side.y)
			{
				side.x += delta.x;
				map.x += step.x;
				hit_side = 0;
			}
			else
			{
				side.y += delta.y;
				map.y += step.y;
				hit_side = 1;
			}
			if (context->map->grid[(int) map.y][(int) map.x] & WALL)
				hit = 1;
		}
		t_vector	wall;
		if (hit_side == 1)
		{
			perp = (map.y - pos.y + (1 - step.y) / 2) / ray.y;
			wall.x = pos.x + perp * ray.x;
		}
		else
		{
			perp = (map.x - pos.x + (1 - step.x) / 2) / ray.x;
			wall.x = pos.y + perp * ray.y;
		}
		line_len = (int) (h / perp);
		draw_start = -line_len / 2 + h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_len / 2 + h / 2;
		if (draw_end >= h)
			draw_end = h - 1;
		for (int i = draw_start; i <= draw_end; i++)
		{
			ft_pixel_put(context->img, x, i, 0xFF);
		}
	}
	// ================================================= //
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
	mlx_hook(context->core->window, 2, 1L << 1, key_press_handler, NULL);
	mlx_loop(context->core->mlx);
}
