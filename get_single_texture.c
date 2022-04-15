/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:21:50 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 20:00:21 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int	convert_str_to_color(char *str)
{
	int	ret;

	ret = 0;
	while (*str && (*str != '\n'))
	{
		if (!ft_isdigit(*str))
			return (-1);
		ret *= 10;
		ret += *str - '0';
		if (ret > 255)
			return (-1);
		str++;
	}
	return (ret);
}

static int	is_valid_color(int *color, char **dptr)
{
	size_t	len;
	int		value;

	len = 0;
	while (dptr[len])
	{
		value = convert_str_to_color(dptr[len]);
		if (value == -1)
			return (0);
		*color <<= 8;
		*color |= value;
		++len;
	}
	return (len == 3);
}

static int	get_color(char *str)
{
	int		ret;
	char	**splitted;

	ret = 0;
	splitted = ft_split(str, ',');
	if (!is_valid_color(&ret, splitted))
		exit_message(NULL, MAP_ERR_MESSAGE, EXIT_FATAL);
	ft_free_cdptr(&splitted);
	return (ret);
}

static void	set_texture_value(t_texture *texture, char **line_info)
{
	if (ft_iseq(line_info[0], NORTH))
		texture->no = ft_substr(line_info[1], 0, ft_strlen(line_info[1]) - 1);
	else if (ft_iseq(line_info[0], SOUTH))
		texture->so = ft_substr(line_info[1], 0, ft_strlen(line_info[1]) - 1);
	else if (ft_iseq(line_info[0], EAST))
		texture->ea = ft_substr(line_info[1], 0, ft_strlen(line_info[1]) - 1);
	else if (ft_iseq(line_info[0], WEST))
		texture->we = ft_substr(line_info[1], 0, ft_strlen(line_info[1]) - 1);
	else if (ft_iseq(line_info[0], FLOOR))
		texture->f = get_color(line_info[1]);
	else if (ft_iseq(line_info[0], CELLING))
		texture->c = get_color(line_info[1]);
}

void	get_single_texture(t_texture *texture, int map_file, size_t *i)
{
	char	*line;
	char	**line_info;

	line = get_next_line(map_file);
	if (!line)
		return ;
	line_info = ft_split(line, ' ');
	if (!*line_info || ft_iseq(*line_info, "\n"))
	{
		ft_free((void **) &line);
		ft_free_cdptr(&line_info);
		return ;
	}
	if (!line_info[1] || line_info[2])
		exit_message(NULL, MAP_ERR_MESSAGE, EXIT_FATAL);
	set_texture_value(texture, line_info);
	(*i)++;
	ft_free((void **) &line);
	ft_free_cdptr(&line_info);
}
