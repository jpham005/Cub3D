/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 03:24:16 by jaham             #+#    #+#             */
/*   Updated: 2021/11/12 03:24:16 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cp;

	cp = (char *) s;
	while (n--)
	{
		if (*cp == (char) c)
			return ((void *) cp);
		cp++;
	}
	return (NULL);
}
