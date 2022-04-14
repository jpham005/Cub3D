/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 05:32:26 by jaham             #+#    #+#             */
/*   Updated: 2021/11/12 05:32:26 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	n_len = ft_strlen(needle);
	i = 0;
	if (n_len == 0)
		return ((char *) haystack);
	while (*(haystack + i) && i < len)
	{
		if (len - i >= n_len && ft_strncmp(haystack + i, needle, n_len) == 0)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
