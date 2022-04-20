/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:54:23 by jaham             #+#    #+#             */
/*   Updated: 2022/04/20 21:00:49 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_delta_dist(t_cast_info *info)
{
	info->delta.x = fabs(1 / info->ray.x);
	info->delta.y = fabs(1 / info->ray.y);
}

void	set_side_dist(t_cast_info *info)
{
	if (info->ray.x < 0)
	{
		info->step.x = -1;
		info->side.x = info->delta.x * (info->pos.x - info->map.x);
	}
	else
	{
		info->step.x = 1;
		info->side.x = info->delta.x * (info->map.x - info->pos.x + 1);
	}
	if (info->ray.y < 0)
	{
		info->step.y = -1;
		info->side.y = info->delta.y * (info->pos.y - info->map.y);
	}
	else
	{
		info->step.y = 1;
		info->side.y = info->delta.y * (info->map.y - info->pos.y + 1);
	}
}
