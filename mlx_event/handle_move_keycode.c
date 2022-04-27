/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move_keycode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:24:09 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 16:33:10 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_move_keycode(int keycode, t_context *context)
{
	if (keycode == KEY_A)
		context->move_dir |= (shift_pos_dir(context->pos_dir, LEFT));
	if (keycode == KEY_D)
		context->move_dir |= (shift_pos_dir(context->pos_dir, RIGHT));
	if (keycode == KEY_W)
		context->move_dir |= (context->pos_dir);
	if (keycode == KEY_S)
		context->move_dir \
			|= (shift_pos_dir(shift_pos_dir(context->pos_dir, RIGHT), RIGHT));
}
