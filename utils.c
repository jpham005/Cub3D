/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:52:46 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 20:49:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

void	exit_message(char *err_str, t_exit_status status)
{
	ft_putstr_fd(err_str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(status);
}

void	ft_pixel_put(t_img *img, size_t x, size_t y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}

void	ft_get_data_addr(t_img *img)
{
	img->addr = mlx_get_data_addr(
		img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian)
		);
}

void	init_vector(t_vector *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}
