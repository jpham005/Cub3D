/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:03:31 by jaham             #+#    #+#             */
/*   Updated: 2022/04/19 15:16:27 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"
# include "t_vector.h"
# include "t_mlx.h"

# define ERR_MESSAGE "Error: "
# define ARG_ERR_MESSAGE ERR_MESSAGE "Usage: ./cub3d file_path"
# define MAP_ERR_MESSAGE ERR_MESSAGE "Wrong map file"
# define MLX_ERR_MESSAGE ERR_MESSAGE "Mlx function error"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TITLE "Cub3d"
# define FOV_DIS 0.5
# define MOVE_DIS 0.1

typedef enum e_exit_status	t_exit_status;
typedef t_map_data			t_dir;
typedef struct s_context	t_context;
typedef enum e_keymap		t_keymap;
typedef enum e_rotate_dir	t_rotate_dir;
typedef struct s_move_info	t_move_info;

enum e_exit_status
{
	SUCCESS = 0,
	EXIT_FATAL = 1
};

enum e_keymap
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_E = 14,
	KEY_ESC = 53,
	KEY_L_A = 123,
	KEY_R_A = 124
};

enum e_rotate_dir
{
	LEFT = 1,
	RIGHT = 2
};

struct s_context
{
	t_map		*map;
	t_vector	pos;
	t_dir		pos_dir;
	t_mlx_core	*core;
	t_img		*img;
	t_dir		move_dir;
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

// mlx event handler
int			key_press_handler(int keycode, void *param);
int			key_release_handler(int keycode, void *param);
void		redraw(t_context *context);

// struct management
// t_context
void		init_context(t_context *context, char *argv);

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
void		ft_pixel_put(t_img *img, size_t x, size_t y, int color);

void		 practice(t_context *context);
#endif