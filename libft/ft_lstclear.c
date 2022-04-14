/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:51:36 by jaham             #+#    #+#             */
/*   Updated: 2021/11/13 14:51:36 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cp;
	t_list	*temp;

	cp = *lst;
	while (cp)
	{
		del(cp->content);
		temp = cp->next;
		free(cp);
		cp = NULL;
		cp = temp;
	}
	*lst = NULL;
}
