/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:39:56 by jaham             #+#    #+#             */
/*   Updated: 2021/11/13 01:39:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	cp;
	char			temp[12];
	char			swap;
	size_t			i;
	size_t			j;

	cp = n * (1 - ((n < 0) << 1));
	i = 0;
	while (cp > 9)
	{
		temp[i++] = cp % 10 + '0';
		cp /= 10;
	}
	temp[i++] = cp % 10 + '0';
	if (n < 0)
		temp[i++] = '-';
	temp[i] = '\0';
	j = 0;
	while (j < i / 2)
	{
		swap = temp[j];
		temp[j] = temp[i - j - 1];
		temp[i - 1 - j++] = swap;
	}
	return (ft_strdup(temp));
}
