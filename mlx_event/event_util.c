/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:57:47 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 16:33:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

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
	return (
		(keycode == KEY_L_A)
		|| (keycode == KEY_R_A)
		|| (keycode == MOUSE_L)
		|| (keycode == MOUSE_R)
	);
}

int	is_door_toggle_keycode(int keycode)
{
	return (keycode == KEY_E);
}

void	redraw(t_context *context)
{
	cast_ray(context);
	mlx_clear_window(context->core->mlx, context->core->window);
	mlx_put_image_to_window(context->core->mlx, \
								context->core->window, context->img->img, 0, 0);
	draw_minimap(context);
}

t_dir	shift_pos_dir(t_dir curr, t_rotate_dir dir)
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
