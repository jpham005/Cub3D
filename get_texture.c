/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:57:59 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 17:24:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static t_texture	*init_texture(void)
{
	t_texture	*ret;

	ret = ft_malloc(sizeof(t_texture), 1);
	ft_memset(ret, 0, sizeof(t_texture));
	ret->f = -1;
	ret->c = -1;
	return (ret);
}

static int	is_wrong_texture(t_texture *texture)
{
	return (!texture || !texture->no || !texture->so || !texture->we \
			|| !texture->ea || (texture->f == -1) || (texture->c == -1));
}

void	get_texture(t_map *map, int map_file)
{
	t_texture	*new;
	size_t		i;

	new = init_texture();
	i = 0;
	while (i < 6)
		get_single_texture(new, map_file, &i);
	if (is_wrong_texture(new))
		exit_message(NULL, MAP_ERR_MESSAGE, EXIT_FATAL);
	map->texture = new;
}
