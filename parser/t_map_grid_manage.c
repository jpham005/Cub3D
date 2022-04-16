/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_grid_manage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:42:38 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 11:34:32 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_map_grid	*init_map_grid(void)
{
	t_map_grid	*ret;

	ret = ft_malloc(sizeof(t_map_grid), 1);
	ft_memset(ret, 0, sizeof(t_map_grid));
	return (ret);
}

void	del_map_grid(t_map_grid **map_grid)
{
	clear_grid_node(&((*map_grid)->head));
	ft_free((void **) map_grid);
}
