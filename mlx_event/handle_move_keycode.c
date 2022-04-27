/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move_keycode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:24:09 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 14:46:29 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dir	shift_pos_dir(t_dir curr, t_rotate_dir dir)
{
	if (dir == LEFT)
	{
		curr <<= 1;
		if (!(curr & PLAYER))
			curr = POS_N;
	}
	else
	{
		curr >>= 1;
		if (!(curr & PLAYER))
			curr = POS_E;
	}
	return (curr);
}

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

void	handle_move_keycode(int keycode, t_context *context)
{
	t_dir	dir;

	dir = 0;
	if (keycode == KEY_A)
		dir |= (shift_pos_dir(context->pos_dir, LEFT));
	if (keycode == KEY_D)
		dir |= (shift_pos_dir(context->pos_dir, RIGHT));
	if (keycode == KEY_W)
		dir |= (context->pos_dir);
	if (keycode == KEY_S)
		dir |= (shift_pos_dir(shift_pos_dir(context->pos_dir, RIGHT), RIGHT));
	move_pos(dir, context);
}
