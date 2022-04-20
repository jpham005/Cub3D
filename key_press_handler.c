/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 16:27:57 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int	is_move_keycode(int keycode)
{
	return (
		(keycode == KEY_A)
		|| (keycode == KEY_D)
		|| (keycode == KEY_W)
		|| (keycode == KEY_S)
	);
}

int	is_turn_keycode(int keycode)
{
	return ((keycode == KEY_L_A) || (keycode == KEY_R_A));
}

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

int	is_valid_point(double x, double y, t_map *map)
{
	return (
		x >= 0
		&& x + 0.1 < map->width
		&& x - 0.1 > 0
		&& y >= 0
		&& y + 0.1 < map->height
		&& y - 0.1 > 0
		&& !(map->grid[(int) y][(int) (x + 0.1)] & WALL)
		&& !(map->grid[(int) y][(int) (x - 0.1)] & WALL)
		&& !(map->grid[(int) (y + 0.1)][(int) x] & WALL)
		&& !(map->grid[(int) (y - 0.1)][(int) x] & WALL)
		&& !(map->grid[(int) (y + 0.1)][(int) (x + 0.1)] & WALL)
		&& !(map->grid[(int) (y + 0.1)][(int) (x - 0.1)] & WALL)
		&& !(map->grid[(int) (y - 0.1)][(int) (x + 0.1)] & WALL)
		&& !(map->grid[(int) (y - 0.1)][(int) (x - 0.1)] & WALL)
	);
}

void	move_pos(t_dir dir, t_context *context)
{
	if ((dir & POS_N) && is_valid_point(context->pos.x, context->pos.y - MOVE_DIS, context->map))
		context->pos.y -= MOVE_DIS;
	if ((dir & POS_W) && is_valid_point(context->pos.x - MOVE_DIS, context->pos.y, context->map))
		context->pos.x -= MOVE_DIS;
	if ((dir & POS_S) && is_valid_point(context->pos.x, context->pos.y + MOVE_DIS, context->map))
		context->pos.y += MOVE_DIS;
	if ((dir & POS_E) && is_valid_point(context->pos.x + MOVE_DIS, context->pos.y, context->map))
		context->pos.x += MOVE_DIS;
}

static void	handle_move_keycode(int keycode, t_context *context)
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

static t_rotate_dir	handle_turn_keycode(int keycode, t_context *context)
{
	if (keycode == KEY_L_A)
	{
		context->pos_dir <<= 1;
		if (!(context->pos_dir & PLAYER))
			context->pos_dir = POS_N;
	}
	if (keycode == KEY_R_A)
	{
		context->pos_dir >>= 1;
		if (!(context->pos_dir & PLAYER))
			context->pos_dir = POS_E;
	}
	return (0);
}

int	key_press_handler(int keycode, void *param)
{
	t_context	*context;

	context = (t_context *) param;
	if (keycode == KEY_ESC)
		exit(0);
	if (is_move_keycode(keycode))
		handle_move_keycode(keycode, context);
	if (is_turn_keycode(keycode))
		handle_turn_keycode(keycode, context);
	redraw(context);
	return (0);
}
