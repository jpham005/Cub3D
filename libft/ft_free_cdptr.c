/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cdptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:53:00 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 15:59:22 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_cdptr(char ***ptr)
{
	size_t	i;

	i = 0;
	while ((*ptr)[i])
		ft_free((void **) &(*ptr)[i++]);
	free(*ptr);
	*ptr = NULL;
}
