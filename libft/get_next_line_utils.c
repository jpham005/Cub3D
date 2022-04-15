/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:53:22 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 19:41:10 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*init_string(t_string *string)
{
	string->str = ft_malloc(sizeof(char), 1);
	if (!string->str)
	{
		perror(NULL);
		return (NULL);
	}
	string->size = 1;
	string->len = 0;
	return (string->str);
}

char	*append_string(t_string *string, char c)
{
	char	*temp;

	if (string->len >= string->size)
	{
		temp = ft_malloc(sizeof(char), (string->size << 1));
		if (!temp)
		{
			perror(NULL);
			return (NULL);
		}
		ft_memcpy(temp, string->str, string->len);
		free(string->str);
		string->str = temp;
		string->size <<= 1;
	}
	string->str[string->len++] = c;
	return (string->str);
}

char	*copy_string(t_string *string)
{
	char	*ret;

	if (!string->len)
		return (NULL);
	ret = ft_malloc(sizeof(char), (string->len + 1));
	if (!ret)
	{
		perror(NULL);
		return (NULL);
	}
	ft_memcpy(ret, string->str, string->len);
	ret[string->len] = '\0';
	return (ret);
}

void	lstdel(t_buffer **cur, int fd)
{
	t_buffer	*target;

	while (*cur && (*cur)->fd != fd)
		cur = &((*cur)->next);
	if (*cur)
	{
		target = *cur;
		*cur = (*cur)->next;
		ft_free((void **) &target);
	}
}
