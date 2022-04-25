/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:21:40 by jaham             #+#    #+#             */
/*   Updated: 2022/04/25 22:04:31 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

static char	*get_img_path(t_context *context, t_texture_type type)
{
	if (type == TEX_NORTH)
		return (context->map->texture->no);
	else if (type == TEX_WEST)
		return (context->map->texture->we);
	else if (type == TEX_SOUTH)
		return (context->map->texture->so);
	else if (type == TEX_EAST)
		return (context->map->texture->ea);
	else if (type == TEX_DOOR)
		return (DOOR_TEXTURE);
	else if (type == TEX_SPRITE_1)
		return (SPRITE_TEXTURE_1);
	else if (type == TEX_SPRITE_2)
		return (SPRITE_TEXTURE_2);
	else
		exit_message(TEXTURE_ERR_MESSAGE, EXIT_FATAL);
	return (NULL);
}

static t_img	*choose_img(
	t_context *context, t_texture_type type, int *width, int *height
)
{
	t_img	*img;
	void	*mlx;
	char	*path;

	img = ft_malloc(sizeof(t_img), 1);
	mlx = context->core->mlx;
	path = get_img_path(context, type);
	img->img = mlx_xpm_file_to_image(mlx, path, width, height);
	if (!img)
		exit_message(TEXTURE_ERR_MESSAGE, EXIT_FATAL);
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

int	*load_img(t_context *context, t_texture_type dir)
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
