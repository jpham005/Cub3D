/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sprite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:48:35 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 22:23:35 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_sprite	*init_sprite(double x, double y)
{
	t_sprite	*ret;

	ret = ft_malloc(sizeof(t_sprite), 1);
	ret->x = x;
	ret->y = y;
	return (ret);
}

void	add_sprite(t_map *map, t_sprite *new)
{
	new->next = map->sprites;
	map->sprites = new;
}

void	del_sprite(t_map *map, int x, int y)
{
	t_sprite	*tmp;
	t_sprite	*sprite;

	map->grid[y][x] = FIELD;
	tmp = NULL;
	sprite = map->sprites;
	while (sprite)
	{
		if ((int)(sprite->x) == x && (int)(sprite->y) == y)
		{
			if (tmp)
				tmp->next = sprite->next;
			else
				map->sprites = sprite->next;
			--map->sprite_cnt;
			ft_free((void **) &sprite);
			return ;
		}
		tmp = sprite;
		sprite = sprite->next;
	}
}
