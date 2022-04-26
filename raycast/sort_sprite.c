/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:30:37 by jaham             #+#    #+#             */
/*   Updated: 2022/04/26 17:35:38 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static double	get_dis(t_vector *pos, t_sprite *sprite)
{
	return (
		(pos->x - sprite->x) * (pos->x - sprite->x) \
		+ (pos->y - sprite->y) * (pos->y - sprite->y)
	);
}

static int	compare_distance(t_vector *pos, t_sprite *sprite, t_sprite *cp)
{
	double	sprite_dis;
	double	cp_dis;

	sprite_dis = get_dis(pos, sprite);
	cp_dis = get_dis(pos, cp);
	return (sprite_dis < cp_dis);
}

static void	swap_sprite(t_sprite *sprite, t_sprite *cp)
{
	t_vector	temp;

	temp.x = sprite->x;
	temp.y = sprite->y;
	sprite->x = cp->x;
	sprite->y = cp->y;
	cp->x = temp.x;
	cp->y = temp.y;
}

void	sort_sprite(t_vector *pos, t_sprite *sprite)
{
	t_sprite	*cp;

	while (sprite->next)
	{
		cp = sprite->next;
		while (cp)
		{
			if (!compare_distance(pos, sprite, cp))
				swap_sprite(sprite, cp);
			cp = cp->next;
		}
		sprite = sprite->next;
	}
}
