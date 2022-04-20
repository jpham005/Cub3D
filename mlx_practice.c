/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_practice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:53:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 19:29:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

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

void	cast_ray(t_context *context)
{
	int	*texture[4];
	texture[TEX_NORTH] = load_img(context, TEX_NORTH);
	texture[TEX_WEST] = load_img(context, TEX_WEST);
	texture[TEX_SOUTH] = load_img(context, TEX_SOUTH);
	texture[TEX_EAST] = load_img(context, TEX_EAST);
	int	buffer[WINDOW_HEIGHT][WINDOW_WIDTH];
	// adding celling, floor
	for (int i = 0; i < WINDOW_HEIGHT; i++)
	{
		for (int j = 0; j < WINDOW_WIDTH; j++)
		{
			if (i < WINDOW_HEIGHT / 2)
				buffer[i][j] = context->map->texture->c;
			else
				buffer[i][j] = context->map->texture->f;
		}
	}
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
		wall.x -= floor(wall.x);
		int	texX;

		texX = (int) (wall.x * (double) TEX_WIDTH);
		if (hit_side == 0 && ray.x > 0)
			texX = TEX_WIDTH - texX - 1;
		if (hit_side == 1 && ray.y < 0)
			texX = TEX_WIDTH - texX - 1;

		line_len = (int) (h / perp);
		draw_start = -line_len / 2 + h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_len / 2 + h / 2;
		if (draw_end >= h)
			draw_end = h - 1;

		double	stepstep = 1.0 * TEX_HEIGHT / line_len;
		double	tex_pos = (draw_start - h / 2 + line_len / 2) * stepstep;
		for (int i = draw_start; i <= draw_end; i++)
		{
			// ft_pixel_put(context->img, x, i, 0xff00ff);
			int	texY;
			double start_i = 

			texY = (int) tex_pos & (TEX_HEIGHT - 1);
			tex_pos += stepstep;

			int	*curr_texture;
			if (hit_side == 0)
			{
				if (pos.x < map.x)
					curr_texture = texture[TEX_EAST];
				else
					curr_texture = texture[TEX_WEST];
			}
			if (hit_side == 1)
			{
				if (pos.y < map.y)
					curr_texture = texture[TEX_NORTH];
				else
					curr_texture = texture[TEX_SOUTH];
			}

			int color = curr_texture[TEX_HEIGHT * texY + texX];
			if (hit_side == 1)
				color = (color >> 1) & 0x7f7f7f;
			buffer[i][x] = color;
		}
	}
	for (int i = 0; i < WINDOW_HEIGHT; i++)
	{
		for (int j = 0; j < WINDOW_WIDTH; j++)
		{
			ft_pixel_put(context->img, j, i, buffer[i][j]);
			// context->img->addr[i * WINDOW_WIDTH + j] = buffer[i][j];
		}
	}
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
}

void	redraw(t_context *context)
{
	mlx_destroy_image(context->core->mlx, context->img->img);
	context->img->img = mlx_new_image(context->core->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	context->img->addr = mlx_get_data_addr(context->img->img, &(context->img->bits_per_pixel), &(context->img->line_length), &(context->img->endian));
	cast_ray(context);
	mlx_clear_window(context->core->mlx, context->core->window);
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
}

void	practice(t_context *context)
{
	// ================================================= //
	// cast single ray
	cast_ray(context);
	// ================================================= //
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
	mlx_hook(context->core->window, 2, 1L << 2, key_press_handler, context);
	mlx_loop(context->core->mlx);
}
