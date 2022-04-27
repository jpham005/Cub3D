/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:01:39 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 22:18:41 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	get_color_value(char *str)
{
	size_t	i;
	char	*temp;
	int		ret;

	ret = 0;
	if (!str)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	i = 0;
	temp = ft_strtrim(str, " ,\t\n");
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]))
			exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
		ret *= 10;
		ret += temp[i] - '0';
		if (ret > 255)
			exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
		++i;
	}
	ft_free((void **) &temp);
	return (ret);
}

int	get_color(char **line_info)
{
	int	ret;

	ret = get_color_value(line_info[1]) << 16;
	ret |= get_color_value(line_info[2]) << 8;
	ret |= get_color_value(line_info[3]);
	if (line_info[4])
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	return (ret);
}
