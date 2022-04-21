/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:38:28 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 15:25:04 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc != 2)
		exit_message(ARG_ERR_MESSAGE, EXIT_FATAL);
	init_context(&context, argv[1]);
	cast_ray(&context);
	mlx_put_image_to_window(context.core->mlx, context.core->window, \
														context.img->img, 0, 0);
	mlx_hook(context.core->window, 2, 1L << 2, key_press_handler, &context);
	mlx_loop(context.core->mlx);
}
