/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door_toggle_keycode.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:49:30 by jaham             #+#    #+#             */
/*   Updated: 2022/04/23 04:23:58 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_pos_dir(t_vector *curr, t_dir pos_dir)
{
	if (pos_dir & POS_E)
		curr->x += 1;
	else if (pos_dir & POS_N)
		curr->y -= 1;
	else if (pos_dir & POS_W)
		curr->x -= 1;
	else if (pos_dir & POS_S)
		curr->y += 1;
}

static int	is_door(t_vector *curr, t_context *context)
{
	return (context->map->grid[(int) curr->y][(int) curr->x] & DOOR);
}

static void	toggle_door(t_vector *curr, t_context *context)
{
	if (context->map->grid[(int) curr->y][(int) curr->x] & DOOR_CLOSED)
		context->map->grid[(int) curr->y][(int) curr->x] = DOOR_OPEND;
	else
		context->map->grid[(int) curr->y][(int) curr->x] = DOOR_CLOSED;
}

void	handle_door_toggle_keycode(t_context *context)
{
	t_vector	curr;

	curr = context->pos;
	add_pos_dir(&curr, context->pos_dir);
	if (is_door(&curr, context))
		toggle_door(&curr, context);
}
