/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:55:56 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 11:34:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_map	*init_map(void)
{
	t_map	*ret;

	ret = ft_malloc(sizeof(t_map), 1);
	ft_memset(ret, 0, sizeof(t_map));
	return (ret);
}
