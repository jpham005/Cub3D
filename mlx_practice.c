/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_practice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:53:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 17:05:55 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

int	key_press_handler(int keycode, void *param)
{
	(void) param;
	if (keycode == 53)
		exit(0);
	return (0);
}

typedef struct img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

void	ft_pixel_put(t_img_data *img_data, size_t x, size_t y, int color)
{
	char	*dest;

	dest = img_data->addr + (y * img_data->line_length + x * (img_data->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}

void	practice(t_map *map)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");

	// ================================================= //

	t_img_data	data;
	data.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	for (size_t i = 0; i < WINDOW_HEIGHT / 2; i++)
	{
		for (size_t j = 0; j < WINDOW_WIDTH; j++)
			ft_pixel_put(&data, j, i, map->texture->c);
	}
	for (size_t i = 0; i < WINDOW_HEIGHT / 2; i++)
	{
		for (size_t j = 0; j < WINDOW_WIDTH; j++)
			ft_pixel_put(&data, j, i + WINDOW_HEIGHT / 2, map->texture->f);
	}
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);

	// ================================================= //
	mlx_hook(window, 2, 1L << 1, key_press_handler, NULL);
	mlx_loop(mlx);
}
