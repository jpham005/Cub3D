/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 04:04:46 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 19:02:45 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	draw_player_body(int x, int y, t_context *context)
{
	int	i;
	int	j;

	i = y - 1;
	while (i < y + 2)
	{
		j = x - 1;
		while (j < x + 2)
		{
			ft_pixel_put(context->minimap, j, i, PLAYER_COLOR);
			++j;
		}
		++i;
	}
}

static void	get_step(t_vector *step, t_context *context)
{
	if (context->pos_dir & POS_N)
		step->y = -1;
	else if (context->pos_dir & POS_E)
		step->x = 1;
	else if (context->pos_dir & POS_S)
		step->y = 1;
	else if (context->pos_dir & POS_W)
		step->x = -1;
}

void	draw_player_head(int x, int y, t_context *context)
{
	t_vector	step;
	int			i;

	ft_memset(&step, 0, sizeof(t_vector));
	get_step(&step, context);
	i = 0;
	while (i < PLAYER_HEAD_LEN)
	{
		ft_pixel_put(context->minimap, x, y, PLAYER_COLOR);
		x += step.x;
		y += step.y;
		++i;
	}
}

void	draw_player(t_context *context)
{
	int	x;
	int	y;

	x = context->pos.x * ((int) MINIMAP_WIDTH / context->map->width);
	y = context->pos.y * ((int) MINIMAP_HEIGHT / context->map->height);
	draw_player_body(x, y, context);
	draw_player_head(x, y, context);
}
