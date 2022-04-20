/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_practice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:53:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 23:08:15 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	cast_ray(t_context *context)
{
	int			hit;
	int			hit_side;
	double		perp;
	int			line_len;
	int			h = WINDOW_HEIGHT;
	int			draw_start;
	int			draw_end;

	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
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
