/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:46:28 by jaham             #+#    #+#             */
/*   Updated: 2021/11/13 03:46:28 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			temp[11];
	char			swap;
	unsigned int	cp;
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
	j = 0;
	while (j < i / 2)
	{
		swap = temp[j];
		temp[j] = temp[i - j - 1];
		temp[i - j - 1] = swap;
		j++;
	}
	write(fd, temp, i);
}
