/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:37:19 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 13:20:01 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>

/*
프로토타입
argv로 맵 경로를 얻어 열고, 유효성 검사 후 해당 fd 반환

과정
1. 확장자 `.cub' 가 들어가는지 확인, 없다면 Map 에러 출력 후 exit(1)
2. open call 후, 실패했다면 Map 에러 에러 출력 후 exit(1)
3. 성공 시 fd 반환
*/
static int	open_map(char *argv)
{
	int	ret;

	if (!ft_iseq(argv + ft_strlen(argv) - 4, ".cub"))
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	ret = open(argv, O_RDONLY);
	if (ret == -1)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
	return (ret);
}

/*
프로토타입
맵 데이터 저장을 위해 map 구조체 받기, argv로 맵 파일 경로 받기
맵 파일에 에러 발생 시, 메세지 출력 후 그자리에서 exit(1)

과정
1. 맵 열기
2. 맵의 텍스쳐 정보 가져오기
3. 맵 좌표 정보 가져오기
4. 맵 닫기
5. 좌표 유효한지 검사하기
*/
void	parse_map(t_map *map, char *argv)
{
	int			map_file;

	map_file = open_map(argv);
	get_texture(map, map_file);
	get_grid(map, map_file);
	close(map_file);
	check_grid(map);
}
