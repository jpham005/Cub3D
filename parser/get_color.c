/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:01:39 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 12:40:18 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int	get_color_value(char *str)
{
	int	ret;

	ret = 0;
	while (*str && (*str != '\n'))
	{
		if (!ft_isdigit(*str))
			exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
		ret *= 10;
		ret += *str - '0';
		if (ret > 255)
			exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
		str++;
	}
	return (ret);
}

/*
프로토타입
`,'로 구분된 이중 포인터에서 color에 데이터 저장

과정
1. value에 R, G, B 중 하나 받기
2. color에 8비트 단위로 저장
3. 3번만 수행하지 않았다면 exit(1)
*/
static void	convert_str_to_color(int *color, char **dptr)
{
	size_t	len;
	int		value;

	len = 0;
	while (dptr[len])
	{
		value = get_color_value(dptr[len]);
		*color <<= 8;
		*color |= value;
		++len;
	}
	if (len != 3)
		exit_message(MAP_ERR_MESSAGE, EXIT_FATAL);
}

/*
프로토타입
컬러 정보가 있는 str, int형으로 RGB 반환

과정
1. `,' 기준으로 str 분할
2. color로 변환 시도, 에러 발생 시 exit(1)
3. 분할 한 splitted free
*/
int	get_color(char *str)
{
	int		ret;
	char	**splitted;

	ret = 0;
	splitted = ft_split(str, ',');
	convert_str_to_color(&ret, splitted);
	ft_free_cdptr(&splitted);
	return (ret);
}
