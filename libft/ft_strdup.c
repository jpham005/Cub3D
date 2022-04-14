/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 07:15:58 by jaham             #+#    #+#             */
/*   Updated: 2021/11/12 07:15:58 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	ret = malloc(sizeof(char) * (s_len + 1));
	if (ret == NULL)
		return (NULL);
	while (s_len--)
		*(ret + i++) = *(s++);
	*(ret + i) = '\0';
	return (ret);
}
