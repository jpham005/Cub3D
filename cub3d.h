/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:03:31 by jaham             #+#    #+#             */
/*   Updated: 2022/04/21 15:25:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "map.h"
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
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef enum e_exit_status	t_exit_status;
typedef t_map_data			t_dir;
typedef struct s_context	t_context;
typedef enum e_keymap		t_keymap;
typedef enum e_rotate_dir	t_rotate_dir;
typedef struct s_move_info	t_move_info;
typedef enum e_texture_dir	t_texture_dir;
typedef struct s_cast_info	t_cast_info;
typedef enum e_hit_side		t_hit_side;
typedef struct s_vector		t_vector;

struct s_vector
{
	double	x;
	double	y;
};

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
	int			*texture[4];
};

enum e_texture_dir
{
	TEX_NORTH = 0,
	TEX_WEST,
	TEX_SOUTH,
	TEX_EAST
};

enum e_hit_side
{
	X_SIDE = 0,
	Y_SIDE = 1
};

struct s_cast_info
{
	int			buffer[WINDOW_HEIGHT][WINDOW_WIDTH];
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	camera;
	t_vector	map;
	t_vector	ray;
	t_vector	side;
	t_vector	delta;
	t_vector	step;
	t_vector	wall;
	int			hit;
	t_hit_side	hit_side;
	double		perp;
	int			line_len;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	double		tex_step;
	double		tex_pos;
};

// parse map
void			parse_map(t_map *map, char *argv);

// get texture
void			get_texture(t_map *map, int map_file);

// get single texture
void			get_single_texture(t_texture *texture, int map_file, size_t *i);

// get color
int				get_color(char *str);

// get grid
void			get_grid(t_map *map, int map_file);

// get grid list
t_map_grid		*get_grid_list(int map_file);

//check grid
void			check_grid(t_map *map);

// load img
int				*load_img(t_context *context, t_texture_dir dir);

// check field point
void			check_field_point(t_map *map, size_t i, size_t j);

// check player point
void			check_player_point(t_map *map, size_t i, size_t j, \
															size_t *player_cnt);

// raycast
void			cast_ray(t_context *context);

// caculate texture
void			calculate_texture(t_cast_info *info, int x, t_context *context);

// raycast util
void			set_buffer_default(int buffer[WINDOW_HEIGHT][WINDOW_WIDTH], \
															t_texture *texture);
void			set_dir_vector(t_vector *dir, t_map_data pos_dir);
void			set_plane_vector(t_vector *plane, t_map_data pos_dir);
void			set_ray_vector(t_cast_info *info);
void			set_delta_dist(t_cast_info *info);
void			set_side_dist(t_cast_info *info);

// mlx event handler
int				key_press_handler(int keycode, void *param);

// handle turn keycode
t_rotate_dir	handle_turn_keycode(int keycode, t_context *context);

// handle move keycode
void			handle_move_keycode(int keycode, t_context *context);

// struct management
// t_context
void			init_context(t_context *context, char *argv);

// mlx
t_mlx_core		*init_mlx(void);
t_img			*init_img(t_mlx_core *core);

// t_map
t_map			*init_map(void);

// t_map_grid
t_map_grid		*init_map_grid(void);
void			del_map_grid(t_map_grid **map_grid);

// t_grid_node
void			add_grid_node(t_grid_node **head, t_map_data data);
void			clear_grid_node(t_grid_node **head);

// utils
void			exit_message(char *err_str, t_exit_status status);
void			ft_pixel_put(t_img *img, size_t x, size_t y, int color);
void			ft_get_data_addr(t_img *img);
void			init_vector(t_vector *vector, double x, double y);
int				is_flipped(t_cast_info *info);

#endif
