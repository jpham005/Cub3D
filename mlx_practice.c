/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_practice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:53:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/19 22:35:14 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	draw_base(t_context *context)
{
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

int	*load_img(t_context *context)
{
	t_img	img;
	int		width;
	int		height;
	int		*ret;

	img.img = mlx_xpm_file_to_image(context->core->mlx, context->map->texture->no, &width, &height);
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	ret = ft_malloc(sizeof(int), width * height);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			ret[width * y + x] = img.addr[width * y + x];
		}
	}
	int temp;
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temp = ret[width * i + j];
				printf("%x %x %x\n", (temp >> 16) & 255, (temp >> 8) & 255, temp & 255);
			}
		}
	}
	mlx_destroy_image(context->core->mlx, img.img);
	return (ret);
}

void	cast_ray(t_context *context)
{
	int	*texture = load_img(context);
	unsigned int	buffer[WINDOW_HEIGHT][WINDOW_WIDTH];
	ft_memset(buffer, 0, WINDOW_HEIGHT * WINDOW_WIDTH);
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

			texY = (int) tex_pos & (TEX_HEIGHT - 1);
			tex_pos += stepstep;
			int color = texture[TEX_HEIGHT * texY + texX];
			if (hit_side == 1)
				color = (color >> 1) & 0x7f7f7f;
			buffer[i][x] = 0xffaaff;
		}
	}
	for (int i = 0; i < WINDOW_HEIGHT; i++)
	{
		for (int j = 0; j < WINDOW_WIDTH; j++)
		{
			context->img->addr[i * WINDOW_WIDTH + j] = buffer[i][j];
		}
	}
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
}

void	redraw(t_context *context)
{
	mlx_destroy_image(context->core->mlx, context->img->img);
	context->img->img = mlx_new_image(context->core->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	context->img->addr = mlx_get_data_addr(context->img->img, &(context->img->bits_per_pixel), &(context->img->line_length), &(context->img->endian));
	draw_base(context);
	cast_ray(context);
	mlx_clear_window(context->core->mlx, context->core->window);
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
}

void	practice(t_context *context)
{
	// ================================================= //
	// draw celling, floor
	draw_base(context);
	// ================================================= //
	// cast single ray
	cast_ray(context);
	// ================================================= //
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
	mlx_hook(context->core->window, 2, 1L << 2, key_press_handler, context);
	mlx_loop(context->core->mlx);
}
