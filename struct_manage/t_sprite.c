/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sprite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:48:35 by jaham             #+#    #+#             */
/*   Updated: 2022/04/25 20:57:00 by jaham            ###   ########.fr       */
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
