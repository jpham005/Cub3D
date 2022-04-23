/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:38:28 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 12:16:59 by jaham            ###   ########.fr       */
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
	set_mlx_event_handler(&context);
	mlx_loop(context.core->mlx);
}
