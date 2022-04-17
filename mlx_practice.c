/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_practice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:53:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/17 16:43:00 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

int	key_press_handler(int keycode, void *param)
{
	(void) param;
	if (keycode == 53)
		exit(0);
	return (0);
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
	mlx_put_image_to_window(context->core->mlx, context->core->window, context->img->img, 0, 0);
	// ================================================= //
	// cast single ray
	t_vector	start;
	t_vector	side_dist;
	t_vector	delta_dist;
	start.x = (int) context->pos.x;
	start.y = (int) context->pos.y;
	side_dist.y = context->pos.y - ((int) context->pos.y);
	delta_dist.y = 1;
	double	w;
	if (context->pos_dir & POS_N)
	{
		while (1)
		{
			// compare side dist
			side_dist.y += delta_dist.y;
			start.y += 1;
			if (context->map->grid[(int) start.x][(int) start.y] & WALL)
				w = side_dist.y - delta_dist.y;
			break ;
		}
	}
	size_t	p = sqrt()
	// ================================================= //
	mlx_hook(context->core->window, 2, 1L << 1, key_press_handler, NULL);
	mlx_loop(context->core->mlx);
}
