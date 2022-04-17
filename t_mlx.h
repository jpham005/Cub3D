/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:46:25 by jaham             #+#    #+#             */
/*   Updated: 2022/04/17 13:51:32 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MLX_H
# define T_MLX_H

typedef struct s_mlx_core	t_mlx_core;
typedef struct s_img		t_img;

struct s_mlx_core
{
	void	*mlx;
	void	*window;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

#endif
