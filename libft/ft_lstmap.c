/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:24:23 by jaham             #+#    #+#             */
/*   Updated: 2021/11/13 15:24:23 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	head;
	t_list	*curr;

	curr = &head;
	while (lst)
	{
		curr->next = malloc(sizeof(t_list));
		if (curr->next == NULL)
		{
			ft_lstclear(&(head.next), del);
			return (NULL);
		}
		curr->next->content = f(lst->content);
		curr = curr->next;
		lst = lst->next;
	}
	curr->next = NULL;
	return (head.next);
}
