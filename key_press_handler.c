/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/19 15:18:49 by jaham            ###   ########.fr       */
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

static t_dir	handle_move_keycode(int keycode, t_context *context)
{
	if (keycode == KEY_A)
		return (shift_pos_dir(context->pos_dir, LEFT));
	if (keycode == KEY_D)
		return (shift_pos_dir(context->pos_dir, RIGHT));
	if (keycode == KEY_W)
		return (context->pos_dir);
	if (keycode == KEY_S)
		return (shift_pos_dir(shift_pos_dir(context->pos_dir, RIGHT), RIGHT));
	return (0);
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
	redraw(context);
	return (0);
}

int	key_press_handler(int keycode, void *param)
{
	t_context	*context;

	context = (t_context *) param;
	if (keycode == KEY_ESC)
		exit(0);
	if (is_move_keycode(keycode))
		context->move_dir |= handle_move_keycode(keycode, context);
	if (is_turn_keycode(keycode))
		handle_turn_keycode(keycode, context);
	return (0);
}

int	key_release_handler(int keycode, void *param)
{
	t_context *context;

	context = (t_context *) param;
	if (is_move_keycode(keycode))
		context->move_dir &= ~handle_move_keycode(keycode, context);
	return (0);
}
