/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:02:56 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 04:04:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

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
