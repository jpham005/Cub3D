/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:37:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 20:24:06 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>

static int	open_map(char *argv)
{
	int	ret;

	if (!ft_iseq(argv + ft_strlen(argv) - 4, ".cub"))
		exit_message(NULL, MAP_ERR_MESSAGE, EXIT_FATAL);
	ret = open(argv, O_RDONLY);
	if (ret == -1)
		exit_message(ERR_MESSAGE, strerror(errno), EXIT_FATAL);
	return (ret);
}

void	parse_map(t_map *map, char *argv)
{
	int			map_file;

	map_file = open_map(argv);
	get_texture(map, map_file);
	get_grid(map, map_file);
	close(map_file);
}
