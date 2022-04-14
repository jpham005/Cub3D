/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:04:43 by jaham             #+#    #+#             */
/*   Updated: 2022/04/14 20:10:24 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

int	init_mlx(t_mlx *mlx)
{
	mlx = ft_malloc(sizeof(t_mlx), 1);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(FATAL);
	mlx->mlx_window = mlx_new_window(mlx->mlx, 1920, 1080, "cub3d");
	if (!mlx->mlx_window)
		exit(FATAL);
	
}
