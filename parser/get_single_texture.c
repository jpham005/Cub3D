/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:21:50 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 20:43:57 by dha              ###   ########seoul.kr  */
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
	else
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}

static void	clear_line(char **line, char ***line_info)
{
	ft_free((void **) line);
	ft_free_cdptr(line_info);
}

/*
프로토타입
텍스쳐 저장을 위해 t_texutre 받기, 읽는 map fd 받기, 몇개의 정보를 읽었는지 받기

과정
1. 한 줄 line에 받기
2. 해당 줄이 eof인지 검사, eof이면 exit(1) (맵 좌표가 확정적으로 존재하지 않게 되기 때문)
3. line을 공백으로 split (공백은 여러개 가능)
4. 줄 전체가 공백이거나 개행 만 들어가 있다면 해당 줄 생략 (전체가 공백인 경우, 다음 호출에서 에러)
5. 데이터 값이 될 line_info[1]이 없거나, 쓸데없는 데이터인 line_info[2]가 존재하면 exit(1)
6. line_info를 바탕으로 데이터 저장
7. 한 종류의 데이터를 읽었으므로 i 증가
8. free 후 종료
*/
void	get_single_texture(t_texture *texture, int map_file, size_t *i)
{
	char	*line;
	char	**line_info;

	line = get_next_line(map_file);
	if (!line)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	line_info = ft_split(line, ' ');
	if (!*line_info || ft_iseq(*line_info, "\n"))
	{
		clear_line(&line, &line_info);
		return ;
	}
	if (!line_info[1] || line_info[2])
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	set_texture_value(texture, line_info);
	(*i)++;
	clear_line(&line, &line_info);
}
