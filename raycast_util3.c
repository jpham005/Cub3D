/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:06:21 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 23:06:32 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_flipped(t_cast_info *info)
{
	return (
		((info->hit_side == X_SIDE) && (info->ray.x > 0))
		|| ((info->hit_side == Y_SIDE) && (info->ray.y < 0))
	);
}
