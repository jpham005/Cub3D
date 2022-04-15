/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:44:03 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 21:18:44 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static t_grid_node	*init_grid_node(t_map_data data)
{
	t_grid_node	*ret;

	ret = ft_malloc(sizeof(t_grid_node), 1);
	ret->data = data;
	ret->next = NULL;
	return (ret);
}

void	add_grid_node(t_grid_node **head, t_map_data data)
{
	if (data == WRONG)
		exit_message(NULL, MAP_ERR_MESSAGE, EXIT_FATAL);
	while (*head)
		head = &((*head)->next);
	*head = init_grid_node(data);
}

void	clear_grid_node(t_grid_node **head)
{
	t_grid_node	*temp;

	while (*head)
	{
		temp = (*head)->next;
		ft_free((void **) head);
		*head = temp;
	}
}
