/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:46:02 by jaham             #+#    #+#             */
/*   Updated: 2021/11/12 02:46:02 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cp;

	cp = (char *) s;
	while (*cp)
		cp++;
	while (1)
	{
		if (*cp == (char) c)
			return (cp);
		if (cp == s)
			return (NULL);
		cp--;
	}
}
