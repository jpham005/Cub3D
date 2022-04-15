/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:24:09 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 21:45:05 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static t_map_data	get_map_data(char c)
{
	if (c == ' ')
		return (SPACE);
	if (c == '0')
		return (FIELD);
	if (c == '1')
		return (WALL);
	if (c == 'N')
		return (POS_N);
	if (c == 'S')
		return (POS_S);
	if (c == 'E')
		return (POS_E);
	if (c == 'W')
		return (POS_W);
	if (c == '\n')
		return (END_LINE);
	return (WRONG);
}

static void	add_line_to_grid(t_map_grid *map_grid, char *line)
{
	size_t		width;
	t_map_data	data;

	width = 0;
	while (*line)
	{
		data = get_map_data(*line);
		add_grid_node(&(map_grid->head), data);
		++line;
		if (data != END_LINE)
			++width;
	}
	if (!width)
		exit_message(NULL, MAP_ERR_MESSAGE, EXIT_FATAL);
	if (width > map_grid->width)
		map_grid->width = width;
}

char	*set_to_content_line(int map_file)
{
	char	*ret;

	while (1)
	{
		ret = get_next_line(map_file);
		if (!ret)
			return (NULL);
		if (!ft_iseq(ret, "\n"))
			break ;
		ft_free((void **) &ret);
	}
	return (ret);
}

t_map_grid	*get_grid_list(int map_file)
{
	t_map_grid	*ret;
	char		*line;

	ret = init_map_grid();
	line = set_to_content_line(map_file);
	while (1)
	{
		if (!line)
			break ;
		add_line_to_grid(ret, line);
		++(ret->height);
		ft_free((void **) &line);
		line = get_next_line(map_file);
	}
	return (ret);
}
