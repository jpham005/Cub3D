/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:12:05 by jaham             #+#    #+#             */
/*   Updated: 2022/04/15 22:46:33 by jaham            ###   ########.fr       */
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
	FIELD = 0,
	WALL = 1,
	SPACE = 2,
	POS_N = 3,
	POS_S = 4,
	POS_E = 5,
	POS_W = 6,
	END_LINE = 7,
	WRONG
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
	size_t		grid_width;
	size_t		grid_height;
};

#endif
