/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 22:52:49 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int	key_press_handler(int keycode, t_context *context)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (is_move_keycode(keycode))
		handle_move_keycode(keycode, context);
	else if (is_turn_keycode(keycode))
		handle_turn_keycode(keycode, context);
	redraw(context);
	return (0);
}
