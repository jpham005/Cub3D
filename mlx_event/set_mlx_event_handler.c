/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_event_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:14:31 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 16:33:34 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

static int	button_press_handler(int keycode, int x, int y, t_context *context)
{
	(void) x;
	(void) y;
	if (is_turn_keycode(keycode + MOUSE_CODE))
		handle_turn_keycode(keycode + MOUSE_CODE, context);
	redraw(context);
	return (0);
}

static int	key_press_handler(int keycode, t_context *context)
{
	if (keycode == KEY_ESC)
		exit(SUCCESS);
	if (is_move_keycode(keycode))
		handle_move_keycode(keycode, context);
	if (is_turn_keycode(keycode))
		handle_turn_keycode(keycode, context);
	if (is_door_toggle_keycode(keycode))
		handle_door_toggle_keycode(context);
	redraw(context);
	return (0);
}

static int	key_release_handler(int keycode, t_context *context)
{
	if (keycode == KEY_A)
		context->move_dir &= ~(shift_pos_dir(context->pos_dir, LEFT));
	if (keycode == KEY_D)
		context->move_dir &= ~(shift_pos_dir(context->pos_dir, RIGHT));
	if (keycode == KEY_W)
		context->move_dir &= ~(context->pos_dir);
	if (keycode == KEY_S)
		context->move_dir \
			&= ~(shift_pos_dir(shift_pos_dir(context->pos_dir, RIGHT), RIGHT));
	return (0);
}

static int	red_cross_handler(void *param)
{
	(void) param;
	exit(SUCCESS);
}

void	set_mlx_event_handler(t_context *context)
{
	mlx_hook(context->core->window, KEY_PRESS, KEY_PRESS_MASK, \
												key_press_handler, context);
	mlx_hook(context->core->window, KEY_RELEASE, KEY_RELEASE_MASK, \
												key_release_handler, context);
	mlx_hook(context->core->window, BUTTON_PRESS, BUTTON_PRESS_MASK, \
											button_press_handler, context);
	mlx_hook(context->core->window, DESTROY_NOTIFY, DESTROY_NOTIFY_MASK, \
													red_cross_handler, NULL);
	mlx_loop_hook(context->core->mlx, move_engine, context);
}
