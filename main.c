/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:38:28 by jaham             #+#    #+#             */
/*   Updated: 2022/04/22 15:34:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc != 2)
		exit_message(ARG_ERR_MESSAGE, EXIT_FATAL);
	init_context(&context, argv[1]);
	cast_ray(&context);
	mlx_put_image_to_window(context.core->mlx, context.core->window, \
														context.img->img, 0, 0);
	draw_minimap(&context);
	mlx_hook(context.core->window, KEY_PRESS, KEY_PRESS_MASK, \
												key_press_handler, &context);
	mlx_hook(context.core->window, BUTTON_PRESS, BUTTON_PRESS_MASK, \
											button_press_handler, &context);
	mlx_loop(context.core->mlx);
}
