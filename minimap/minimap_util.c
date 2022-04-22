/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:53:24 by jaham             #+#    #+#             */
/*   Updated: 2022/04/22 17:31:25 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_outrange(t_context *context, t_minimap *minimap)
{
	return (
		(minimap->curr_x >= context->map->width)
		|| (minimap->curr_y >= context->map->height)
	);
}

void	set_step_xy(t_context *context, t_minimap *minimap)
{
	minimap->step_x = MINIMAP_WIDTH / context->map->width;
	minimap->step_y = MINIMAP_HEIGHT / context->map->height;
	minimap->curr_step_x = minimap->step_x;
	minimap->curr_step_y = minimap->step_y;
	minimap->curr_x = 0;
	minimap->curr_y = 0;
	minimap->pos.x = context->pos.x;
	minimap->pos.y = context->pos.y;
}
