/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:12:05 by jaham             #+#    #+#             */
/*   Updated: 2022/04/25 20:57:53 by jaham            ###   ########.fr       */
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

typedef struct s_texture		t_texture;
typedef enum e_map_data			t_map_data;
typedef enum e_map_data_mask	t_map_data_mask;
typedef struct s_map_grid		t_map_grid;
typedef struct s_map			t_map;
typedef struct s_grid_node		t_grid_node;
typedef struct s_sprite			t_sprite;

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
	DOOR_OPEND = 1 << 10,
	DOOR_CLOSED = 1 << 11,
	SPRITE = 1 << 12,
	DOOR = DOOR_OPEND | DOOR_CLOSED,
	PLAYER = POS_N | POS_S | POS_E | POS_W
};

enum e_map_data_mask
{
	FIELD_MASK = FIELD | WALL | PLAYER | DOOR | SPRITE,
	PLAYER_MASK = WALL | FIELD | DOOR | SPRITE,
	DOOR_MASK = FIELD | WALL | PLAYER | DOOR | SPRITE,
	SPRITE_MASK = FIELD | WALL | PLAYER | DOOR | SPRITE
};

struct s_grid_node
{
	t_map_data	data;
	t_grid_node	*next;
};

struct s_sprite
{
	double		x;
	double		y;
	t_sprite	*next;
};

struct s_map_grid
{
	t_grid_node	*head;
	size_t		width;
	size_t		height;
	size_t		sprite_cnt;
};

struct s_map
{
	t_texture	*texture;
	int			**grid;
	size_t		width;
	size_t		height;
	size_t		sprite_cnt;
	t_sprite	*sprites;
};

#endif
