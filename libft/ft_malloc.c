/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:52:13 by jaham             #+#    #+#             */
/*   Updated: 2022/03/14 14:54:50 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_malloc(size_t el_size, size_t el_num)
{
	void	*ret;

	ret = malloc(el_size * el_num);
	if (!ret)
	{
		perror("malloc: ");
		exit(1);
	}
	return (ret);
}
