/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:38:28 by jaham             #+#    #+#             */
/*   Updated: 2022/04/14 20:04:36 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "cheat.h"
#include "cub3d.h"

int	key_press_handler(int keycode, void *param)
{
	(void) param;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main()
{
	t_mlx	*mlx;

	init_mlx(mlx);
	mlx_hook(mlx_window, 02, 1L << 0, key_press_handler, NULL);
	mlx_loop(mlx);
}
