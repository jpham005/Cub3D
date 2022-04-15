/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:22:56 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 22:52:06 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>
static void	put_single_line(int *grid, t_grid_node **head, size_t width)
{
	size_t	i;

	i = 0;
	while (*head)
	{
		if ((*head)->data != END_LINE)
			grid[i++] = (*head)->data;
		*head = (*head)->next;
	}
	while (i < width)
		grid[i++] = SPACE;
}

static void	put_grid_node(int **grid, t_map_grid *map_grid)
{
	t_grid_node	*cp;
	size_t		i;

	cp = map_grid->head;
	i = 0;
	while (cp)
	{
		grid[i] = ft_malloc(sizeof(int), map_grid->width);
		put_single_line(grid[i++], &cp, map_grid->width);
	}
}

static void	convert_grid_list(t_map *map, t_map_grid *map_grid)
{
	map->grid_width = map_grid->width;
	map->grid_height = map_grid->height;
	map->grid = ft_malloc(sizeof(int *), map_grid->height);
	put_grid_node(map->grid, map_grid);
}

void	get_grid(t_map *map, int map_file)
{
	t_map_grid	*map_grid_list;

	map_grid_list = get_grid_list(map_file);
	convert_grid_list(map, map_grid_list);
	del_map_grid(&map_grid_list);
	for (int i = 0; i < map->grid_width; i++)
	{
		for ()
	}
}
