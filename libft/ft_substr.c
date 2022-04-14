/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 07:24:11 by jaham             #+#    #+#             */
/*   Updated: 2021/11/12 07:24:11 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	str_len;
	size_t	end;

	str_len = ft_strlen(s);
	if (str_len < start + len)
		end = str_len;
	else
		end = start + len;
	if (end < start)
		end = start;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s + start, end - start);
	ret[end - start] = '\0';
	return (ret);
}
