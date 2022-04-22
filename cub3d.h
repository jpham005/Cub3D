/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:03:31 by jaham             #+#    #+#             */
/*   Updated: 2022/04/22 17:04:58 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "event_macro.h"
# include "map.h"
# include "t_mlx.h"

# define ARG_ERR_MESSAGE "Error: Usage: ./cub3d file_path"
# define MAP_ERR_MESSAGE "Error: Wrong map file"
# define MLX_ERR_MESSAGE "Error: Mlx function error"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TITLE "Cub3d"
# define FOV_DIS 0.5
# define MOVE_DIS 0.1
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MINIMAP_WIDTH 250
# define MINIMAP_HEIGHT 250

typedef enum e_exit_status	t_exit_status;
typedef t_map_data			t_dir;
typedef struct s_context	t_context;
typedef struct s_move_info	t_move_info;
typedef enum e_texture_dir	t_texture_dir;
typedef struct s_cast_info	t_cast_info;
typedef enum e_hit_side		t_hit_side;
typedef struct s_vector		t_vector;
typedef struct s_minimap	t_minimap;

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

struct s_context
{
	t_map		*map;
	t_vector	pos;
	t_dir		pos_dir;
	t_mlx_core	*core;
	t_img		*img;
	t_img		*minimap;
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

struct s_minimap
{
	int			step_x;
	int			step_y;
	int			curr_step_x;
	int			curr_step_y;
	size_t		curr_x;
	size_t		curr_y;
	t_vector	pos;
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

// keypress handler
int				key_press_handler(int keycode, t_context *param);

// button press handler
int				button_press_handler(int keycode, \
											int x, int y, t_context *context);

// handle turn keycode
void			handle_turn_keycode(int keycode, t_context *context);

// handle move keycode
void			handle_move_keycode(int keycode, t_context *context);

// event util
int				is_move_keycode(int keycode);
int				is_turn_keycode(int keycode);
void			redraw(t_context *context);

// struct management
// t_context
void			init_context(t_context *context, char *argv);

// mlx
t_mlx_core		*init_mlx(void);
t_img			*init_img(t_mlx_core *core);

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

// draw minimap
void			draw_minimap(t_context *context);

// draw minimap wall
void			draw_minimap_wall(t_context *context, t_minimap *minimap);

// minimap util
int				is_outrange(t_context *context, t_minimap *minimap);
void			set_step_xy(t_context *context, t_minimap *minimap);

#endif
