/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:29:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 16:32:09 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_move_point(double x, double y, t_map *map)
{
	const t_map_data	invalid = WALL | DOOR_CLOSED;

	return (
		x >= 0
		&& x + MOVE_DIS < map->width
		&& x - MOVE_DIS > 0
		&& y >= 0
		&& y + MOVE_DIS < map->height
		&& y - MOVE_DIS > 0
		&& !(map->grid[(int) y][(int)(x + MOVE_DIS)] & invalid)
		&& !(map->grid[(int) y][(int)(x - MOVE_DIS)] & invalid)
		&& !(map->grid[(int)(y + MOVE_DIS)][(int) x] & invalid)
		&& !(map->grid[(int)(y - MOVE_DIS)][(int) x] & invalid)
		&& !(map->grid[(int)(y + MOVE_DIS)][(int)(x + MOVE_DIS)] & invalid)
		&& !(map->grid[(int)(y + MOVE_DIS)][(int)(x - MOVE_DIS)] & invalid)
		&& !(map->grid[(int)(y - MOVE_DIS)][(int)(x + MOVE_DIS)] & invalid)
		&& !(map->grid[(int)(y - MOVE_DIS)][(int)(x - MOVE_DIS)] & invalid)
	);
}

static void	move_pos(t_dir dir, t_context *context)
{
	if ((dir & POS_N) && is_valid_move_point(context->pos.x, \
									context->pos.y - MOVE_DIS, context->map))
		context->pos.y -= MOVE_DIS;
	if ((dir & POS_W) && is_valid_move_point(context->pos.x - MOVE_DIS, \
												context->pos.y, context->map))
		context->pos.x -= MOVE_DIS;
	if ((dir & POS_S) && is_valid_move_point(context->pos.x, \
									context->pos.y + MOVE_DIS, context->map))
		context->pos.y += MOVE_DIS;
	if ((dir & POS_E) && is_valid_move_point(context->pos.x + MOVE_DIS, \
												context->pos.y, context->map))
		context->pos.x += MOVE_DIS;
}

int	move_engine(t_context *context)
{
	move_pos(context->move_dir, context);
	redraw(context);
	return (0);
}
