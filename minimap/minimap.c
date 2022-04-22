/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:02:56 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 03:10:22 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

void	draw_player(t_context *context)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = context->pos.x * ((int) MINIMAP_WIDTH / context->map->width);
	y = context->pos.y * ((int) MINIMAP_WIDTH / context->map->height);
	i = y - 1;
	while (i < y + 2)
	{
		j = x - 1;
		while (j < x + 2)
		{
			ft_pixel_put(context->minimap, j, i, 0xFF0000);
			++j;
		}
		++i;
	}
}

void	draw_minimap(t_context *context)
{
	t_minimap	minimap;

	context->minimap = ft_malloc(sizeof(t_img), 1);
	context->minimap->img = mlx_new_image(context->core->mlx, \
												MINIMAP_WIDTH, MINIMAP_HEIGHT);
	ft_get_data_addr(context->minimap);
	draw_minimap_wall(context, &minimap);
	draw_player(context);
	mlx_put_image_to_window(context->core->mlx, context->core->window, \
												context->minimap->img, 10, 10);
}
