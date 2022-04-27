/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:03:31 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 22:00:19 by jaham            ###   ########.fr       */
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
# define TEXTURE_ERR_MESSAGE "Error: Wrong texture file"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TITLE "Cub3d"
# define FOV_DIS 0.5
# define MOVE_DIS 0.09
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MINIMAP_WIDTH 250
# define MINIMAP_HEIGHT 250
# define DOOR_TEXTURE "./img/wood.xpm"
# define PLAYER_HEAD_LEN 5
# define SPRITE_TEXTURE_1 "./img/heart.xpm"
# define SPRITE_TEXTURE_2 "./img/heart_off.xpm"
# define TIME_SPRITE_SWAP 100

typedef enum e_exit_status		t_exit_status;
typedef t_map_data				t_dir;
typedef struct s_context		t_context;
typedef struct s_move_info		t_move_info;
typedef enum e_texture_type		t_texture_type;
typedef struct s_cast_info		t_cast_info;
typedef struct s_sprite_info	t_sprite_info;
typedef enum e_hit_side			t_hit_side;
typedef struct s_vector			t_vector;
typedef struct s_minimap		t_minimap;

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

enum e_texture_type
{
	TEX_NORTH = 0,
	TEX_WEST,
	TEX_SOUTH,
	TEX_EAST,
	TEX_DOOR,
	TEX_SPRITE_1,
	TEX_SPRITE_2,
	NUM_OF_TEX
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
	int			*texture[NUM_OF_TEX];
	int			curr_sprite;
	int			loop_cnt;
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

struct s_sprite_info
{
	t_vector	pos_sprite;
	t_vector	transform;
	t_vector	draw_start;
	t_vector	draw_end;
	double		sprite_screen_x;
	double		sprite_height;
	double		sprite_width;
	int			tex_x;
	int			tex_y;
	int			d;
	int			y;
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

enum e_minimap_color
{
	FOREGROUND_COLOR = 0xFFFFFF,
	BACKGROUND_COLOR = 0x000000,
	DOOR_COLOR = 0x0FFFF0,
	PLAYER_COLOR = 0xFF0000,
	SPRITE_COLOR = 0x660000
};

// parse map
void			parse_map(t_map *map, char *argv);

// get texture
void			get_texture(t_map *map, int map_file);

// get single texture
void			get_single_texture(t_texture *texture, int map_file, size_t *i);

// get color
int				get_color(char **line_info);

// get grid
void			get_grid(t_map *map, int map_file);

// get grid list
t_map_grid		*get_grid_list(int map_file);

//check grid
void			check_grid(t_map *map);

// load img
int				*load_img(t_context *context, t_texture_type dir);

// check point
int				is_valid_map_point(t_map *map, size_t i, size_t j, \
													t_map_data_mask available);
void			check_player_point(t_map *map, size_t i, size_t j, \
														size_t *player_cnt);
// raycast
void			cast_ray(t_context *context);

// caculate texture
void			calculate_texture(t_cast_info *info, int x, \
							t_context *context, double z_buffer[WINDOW_WIDTH]);

// raycast util
void			set_buffer_default(int buffer[WINDOW_HEIGHT][WINDOW_WIDTH], \
															t_texture *texture);
void			set_dir_vector(t_vector *dir, t_map_data pos_dir);
void			set_plane_vector(t_vector *plane, t_map_data pos_dir);
void			set_ray_vector(t_cast_info *info);
void			set_delta_dist(t_cast_info *info);
void			set_side_dist(t_cast_info *info);
int				is_flipped(t_cast_info *info);

// draw sprite
void			draw_sprite(t_context *context, t_cast_info *info, \
												double z_buffer[WINDOW_WIDTH]);

// sort sprite
void			sort_sprite(t_vector *pos, t_sprite *sprite);

// sprite util
void			set_pos_sprite(t_sprite_info *info, t_context *context, \
															t_sprite *sprite);
void			get_transform_pos(t_sprite_info *sprite_info, \
													t_cast_info *cast_info);
void			calculate_draw_point(t_sprite_info *info);
int				is_inrange_sprite(t_sprite_info *sp_info, \
											double z_buf[WINDOW_WIDTH], int j);

// set mlx event handler
void			set_mlx_event_handler(t_context *context);

// handle turn keycode
void			handle_turn_keycode(int keycode, t_context *context);

// handle move keycode
void			handle_move_keycode(int keycode, t_context *context);

// handle door toggle keycode
void			handle_door_toggle_keycode(t_context *context);

// engine
int				engine(t_context *context);

// event util
int				is_move_keycode(int keycode);
int				is_turn_keycode(int keycode);
int				is_door_toggle_keycode(int keycode);
void			redraw(t_context *context);
t_dir			shift_pos_dir(t_dir curr, t_rotate_dir dir);

// struct management
// t_context
void			init_context(t_context *context, char *argv);

// t_sprite
t_sprite		*init_sprite(double x, double y);
void			add_sprite(t_map *map, t_sprite *new);
void			del_sprite(t_map *map, int x, int y);

// mlx
t_mlx_core		*init_mlx(void);
t_img			*init_img(t_mlx_core *core, int width, int height);

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

// draw minimap
void			draw_minimap(t_context *context);

// draw minimap wall
void			draw_minimap_wall(t_context *context, t_minimap *minimap);

// draw player
void			draw_player(t_context *context);

// minimap util
int				is_outrange(t_context *context, t_minimap *minimap);
void			set_step_xy(t_context *context, t_minimap *minimap);

#endif
