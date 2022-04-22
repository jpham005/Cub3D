/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:12:05 by jaham             #+#    #+#             */
/*   Updated: 2022/04/22 15:48:24 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stddef.h>

# define NORTH "NO"
# define SOUTH "SO"
# define WEST "WE"
# define EAST "EA"
# define FLOOR "F"
# define CELLING "C"

typedef struct s_texture	t_texture;
typedef enum e_map_data		t_map_data;
typedef struct s_map_grid	t_map_grid;
typedef struct s_map		t_map;
typedef struct s_grid_node	t_grid_node;

struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
};

enum e_map_data
{
	FIELD = 1 << 1,
	WALL = 1 << 2,
	SPACE = 1 << 3,
	POS_N = 1 << 4,
	POS_W = 1 << 5,
	POS_S = 1 << 6,
	POS_E = 1 << 7,
	END_LINE = 1 << 8,
	WRONG = 1 << 9,
	DOOR = 1 << 10,
	PLAYER = POS_N | POS_S | POS_E | POS_W
};

struct s_grid_node
{
	t_map_data	data;
	t_grid_node	*next;
};

struct s_map_grid
{
	t_grid_node	*head;
	size_t		width;
	size_t		height;
};

struct s_map
{
	t_texture	*texture;
	int			**grid;
	size_t		width;
	size_t		height;
};

#endif
