/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:21:40 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 03:27:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

static t_img	*choose_img(
	t_context *context, t_texture_dir dir, int *width, int *height
)
{
	t_img	*img;

	img = ft_malloc(sizeof(t_img), 1);
	if (dir == TEX_NORTH)
		img->img = mlx_xpm_file_to_image(context->core->mlx, \
									context->map->texture->no, width, height);
	else if (dir == TEX_WEST)
		img->img = mlx_xpm_file_to_image(context->core->mlx, \
									context->map->texture->we, width, height);
	else if (dir == TEX_SOUTH)
		img->img = mlx_xpm_file_to_image(context->core->mlx, \
									context->map->texture->so, width, height);
	else if (dir == TEX_EAST)
		img->img = mlx_xpm_file_to_image(context->core->mlx, \
									context->map->texture->ea, width, height);
	else if (dir == TEX_DOOR)
		img->img = mlx_xpm_file_to_image(context->core->mlx, \
									DOOR_TEXTURE, width, height);
	return (img);
}

static void	set_texture_buffer(int *ret, int width, int height, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ret[width * y + x] = ((int *)(img->addr))[y * width + x];
			++x;
		}
		++y;
	}
}

int	*load_img(t_context *context, t_texture_dir dir)
{
	t_img	*img;
	int		width;
	int		height;
	int		*ret;

	img = choose_img(context, dir, &width, &height);
	ft_get_data_addr(img);
	ret = ft_malloc(sizeof(int), width * height);
	set_texture_buffer(ret, width, height, img);
	mlx_destroy_image(context->core->mlx, img->img);
	ft_free((void **) &img);
	return (ret);
}
