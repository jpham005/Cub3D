/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:51:45 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 20:15:45 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

t_img	*init_img(t_mlx_core *core)
{
	t_img	*ret;

	ret = ft_malloc(sizeof(t_img), 1);
	ret->img = mlx_new_image(core->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_get_data_addr(ret->img);
	return (ret);
}

t_mlx_core	*init_mlx(void)
{
	t_mlx_core	*ret;

	ret = ft_malloc(sizeof(t_mlx_core), 1);
	ret->mlx = mlx_init();
	if (!ret->mlx)
		exit_message(MLX_ERR_MESSAGE, EXIT_FATAL);
	ret->window = mlx_new_window(ret->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	if (!ret->window)
		exit_message(MLX_ERR_MESSAGE, EXIT_FATAL);
	return (ret);
}
