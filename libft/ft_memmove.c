/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:24:26 by jaham             #+#    #+#             */
/*   Updated: 2021/11/10 17:24:26 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cp_src;
	unsigned char	*cp_dest;

	if (!src && !dest)
		return (NULL);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	cp_src = (unsigned char *) src + (n - 1);
	cp_dest = (unsigned char *) dest + (n - 1);
	while (cp_src >= (unsigned char *) src)
	{
		*(cp_dest--) = *(cp_src--);
	}
	return (dest);
}
