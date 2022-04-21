/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_turn_keycode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:21:39 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 15:57:18 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_turn_keycode(int keycode, t_context *context)
{
	if ((keycode == KEY_L_A) || (keycode == MOUSE_L))
	{
		context->pos_dir <<= 1;
		if (!(context->pos_dir & PLAYER))
			context->pos_dir = POS_N;
	}
	if ((keycode == KEY_R_A) || (keycode == MOUSE_R))
	{
		context->pos_dir >>= 1;
		if (!(context->pos_dir & PLAYER))
			context->pos_dir = POS_E;
	}
}
