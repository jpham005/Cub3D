/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:44:24 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 22:58:57 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	button_press_handler(int keycode, int x, int y, t_context *context)
{
	(void) x;
	(void) y;
	if (is_turn_keycode(keycode))
		handle_turn_keycode(keycode, context);
	redraw(context);
	return (0);
}
