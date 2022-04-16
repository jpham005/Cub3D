/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:03:31 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 16:47:56 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"

# define ERR_MESSAGE "Error: "
# define ARG_ERR_MESSAGE ERR_MESSAGE "Usage: ./cub3d file_path"
# define MAP_ERR_MESSAGE ERR_MESSAGE "Wrong map file"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

typedef struct s_mlx		t_mlx;
typedef enum e_exit_status	t_exit_status;

struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
};

enum e_exit_status
{
	SUCCESS = 0,
	EXIT_FATAL = 1
};

// parse map
void		parse_map(t_map *map, char *argv);

// get texture
void		get_texture(t_map *map, int map_file);

// get single texture
void		get_single_texture(t_texture *texture, int map_file, size_t *i);

// get color
int			get_color(char *str);

// get grid
void		get_grid(t_map *map, int map_file);

// get grid list
t_map_grid	*get_grid_list(int map_file);

//check grid
void		check_grid(t_map *map);

// check field point
void		check_field_point(t_map *map, size_t i, size_t j);

// check player point
void		check_player_point(t_map *map, size_t i, size_t j, \
															size_t *player_cnt);

// struct management
// t_map
t_map		*init_map(void);

// t_map_grid
t_map_grid	*init_map_grid(void);
void		del_map_grid(t_map_grid **map_grid);

// t_grid_node
void		add_grid_node(t_grid_node **head, t_map_data data);
void		clear_grid_node(t_grid_node **head);

// utils
void		exit_message(char *err_str, t_exit_status status);

void practice(t_map *map);
#endif