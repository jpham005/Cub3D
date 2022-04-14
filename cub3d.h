/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:03:31 by jaham             #+#    #+#             */
/*   Updated: 2022/04/14 20:09:26 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_mlx		t_mlx;
typedef enum e_exit_status	t_exit_status;

struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
};

enum e_exit_status
{
	SUCCESS = 0,
	FATAL = 1
};

#endif