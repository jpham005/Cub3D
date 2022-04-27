/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:21:50 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 22:21:52 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/*
프로토타입
texture에 line_info값을 저장

과정
1. line_info[1]은 개행이 포함되어 있으므로, substr으로 마지막 글자 제거
2. 천장과 바닥은 색 정보만 있으므로, get_color로 정보 가져오기
*/
static void	set_texture_value(
	t_texture *texture, char **line_info, size_t comma_cnt
)
{
	if (ft_iseq(line_info[0], NORTH) && !line_info[2])
		texture->no = ft_substr(line_info[1], 0, ft_strlen(line_info[1]));
	else if (ft_iseq(line_info[0], SOUTH) && !line_info[2])
		texture->so = ft_substr(line_info[1], 0, ft_strlen(line_info[1]));
	else if (ft_iseq(line_info[0], EAST) && !line_info[2])
		texture->ea = ft_substr(line_info[1], 0, ft_strlen(line_info[1]));
	else if (ft_iseq(line_info[0], WEST) && !line_info[2])
		texture->we = ft_substr(line_info[1], 0, ft_strlen(line_info[1]));
	else if (ft_iseq(line_info[0], FLOOR) && (comma_cnt == 2))
		texture->f = get_color(line_info);
	else if (ft_iseq(line_info[0], CELLING) && (comma_cnt == 2))
		texture->c = get_color(line_info);
	else
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}

static void	clear_line(char **line, char ***line_info)
{
	ft_free((void **) line);
	ft_free_cdptr(line_info);
}

static size_t	check_comma(char *line)
{
	size_t	cnt;

	cnt = 0;
	while (*line)
	{
		if (*line == ',')
			++cnt;
		++line;
	}
	return (cnt);
}

void	get_single_texture(t_texture *texture, int map_file, size_t *i)
{
	char	*line;
	char	**line_info;
	size_t	comma_cnt;

	line = get_next_line(map_file);
	if (!line)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	comma_cnt = check_comma(line);
	line_info = ft_split(line, " ,\n");
	if (!*line_info)
	{
		clear_line(&line, &line_info);
		return ;
	}
	if (!line_info[1])
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	set_texture_value(texture, line_info, comma_cnt);
	(*i)++;
	clear_line(&line, &line_info);
}
