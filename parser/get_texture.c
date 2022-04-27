/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:57:59 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 20:44:28 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

// 텍스쳐 구조체 초기화
static t_texture	*init_texture(void)
{
	t_texture	*ret;

	ret = ft_malloc(sizeof(t_texture), 1);
	ft_memset(ret, 0, sizeof(t_texture));
	ret->f = -1;
	ret->c = -1;
	return (ret);
}

/*
프로토타입
텍스쳐 정보 저장을 위해 map 구조체 받기, 읽으려는 map의 fd 받기

과정
1. 텍스쳐 구조체 초기화
2. 6개의 정보를 받기, 순서는 무관함 (에러 발생 함수 내 에서 즉시 exit(1))
*/
void	get_texture(t_map *map, int map_file)
{
	size_t		i;

	map->texture = init_texture();
	i = 0;
	while (i < 6)
		get_single_texture(map->texture, map_file, &i);
}
