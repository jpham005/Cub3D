/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_turn_keycode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:21:39 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 17:26:59 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dir	get_rotated_dir(int keycode, t_dir dir)
{
	t_dir	ret;

	if ((keycode == KEY_L_A) || (keycode == MOUSE_L))
	{
		ret = dir << 1;
		if (ret & ~PLAYER)
		{
			ret &= PLAYER;
			ret |= POS_N;
		}
	}
	else
	{
		ret = dir >> 1;
		if (ret & ~PLAYER)
		{
			ret &= PLAYER;
			ret |= POS_E;
		}
	}
	return (ret);
}

void	handle_turn_keycode(int keycode, t_context *context)
{
	context->pos_dir = get_rotated_dir(keycode, context->pos_dir);
	context->move_dir = get_rotated_dir(keycode, context->move_dir);
}
