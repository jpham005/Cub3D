/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:39:22 by jaham             #+#    #+#             */
/*   Updated: 2021/11/12 06:39:22 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	unsigned char	*ret;

	ret = malloc(elsize * nelem);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, elsize * nelem);
	return ((void *) ret);
}
