/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:03:18 by jaham             #+#    #+#             */
/*   Updated: 2022/03/21 15:05:37 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char	*cp_dest;
	unsigned char	*cp_src;
	unsigned char	*end;

	if (dest == src)
		return (dest);
	end = (unsigned char *) src + n;
	cp_dest = (unsigned char *) dest;
	cp_src = (unsigned char *) src;
	while (cp_src < end)
	{
		*(cp_dest++) = *(cp_src++);
	}
	return (dest);
}
