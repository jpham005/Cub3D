/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:29:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 20:00:11 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	del_sprite(t_map *map, int x, int y);

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
	if (context->map->grid[(int)context->pos.y][(int)context->pos.x] & SPRITE)
		del_sprite(context->map, (int) context->pos.x, (int) context->pos.y);
	redraw(context);
	return (0);
}
