/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:29:02 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 21:14:55 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pos_sprite(
	t_sprite_info *info, t_context *context, t_sprite *sprite
)
{
	info->pos_sprite.x = sprite->x - context->pos.x + 0.5;
	info->pos_sprite.y = sprite->y - context->pos.y + 0.5;
}

void	get_transform_pos(
	t_sprite_info *sprite_info, t_cast_info *cast_info
)
{
	double	inv_det;

	inv_det = 1.0 / (cast_info->plane.x * cast_info->dir.y \
									- cast_info->dir.x * cast_info->plane.y);
	sprite_info->transform.x = inv_det * (cast_info->dir.y \
		* sprite_info->pos_sprite.x \
		- cast_info->dir.x * sprite_info->pos_sprite.y);
	sprite_info->transform.y = inv_det * (-cast_info->plane.y \
		* sprite_info->pos_sprite.x \
		+ cast_info->plane.x * sprite_info->pos_sprite.y);
}
