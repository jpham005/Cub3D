/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:57:47 by jaham             #+#    #+#             */
/*   Updated: 2022/04/25 13:37:01 by jaham            ###   ########.fr       */
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
	mlx_destroy_image(context->core->mlx, context->img->img);
	mlx_destroy_image(context->core->mlx, context->minimap->img);
	context->img->img = \
				mlx_new_image(context->core->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_get_data_addr(context->img);
	cast_ray(context);
	mlx_clear_window(context->core->mlx, context->core->window);
	mlx_put_image_to_window(context->core->mlx, \
								context->core->window, context->img->img, 0, 0);
	draw_minimap(context);
}
