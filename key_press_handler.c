/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:41 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 15:28:42 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdlib.h>

static int	is_move_keycode(int keycode)
{
	return (
		(keycode == KEY_A)
		|| (keycode == KEY_D)
		|| (keycode == KEY_W)
		|| (keycode == KEY_S)
	);
}

static int	is_turn_keycode(int keycode)
{
	return ((keycode == KEY_L_A) || (keycode == KEY_R_A));
}

static void	redraw(t_context *context)
{
	mlx_destroy_image(context->core->mlx, context->img->img);
	context->img->img = \
				mlx_new_image(context->core->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_get_data_addr(context->img);
	cast_ray(context);
	mlx_clear_window(context->core->mlx, context->core->window);
	mlx_put_image_to_window(context->core->mlx, \
								context->core->window, context->img->img, 0, 0);
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
