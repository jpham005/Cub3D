# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 22:36:11 by jaham             #+#    #+#              #
#    Updated: 2022/04/22 17:05:17 by jaham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= cub3d

LIBFT_DIR			:= libft
LIBFT_INCLUDE		:= $(LIBFT_DIR)
LIBFT				:= $(LIBFT_DIR)/libft.a

LIBMLX_DIR			:= minilibx_mms_20210621
LIBMLX_INCLUDE		:= $(LIBMLX_DIR)
LIBMLX				:= libmlx.dylib

PARSER_DIR			:= parser
PARSER_SRCS			:= check_field_point.c check_grid.c check_player_point.c \
					   get_color.c get_grid_list.c get_grid.c \
					   get_single_texture.c get_texture.c parse_map.c \
					   t_grid_node_manage.c t_map_grid_manage.c
PARSER_SRCS			:= $(addprefix $(PARSER_DIR)/, $(PARSER_SRCS))

STRUCT_MANAGE_DIR	:= struct_manage
STRUCT_MANAGE_SRCS	:= t_mlx_manage.c t_context_manage.c load_img.c
STRUCT_MANAGE_SRCS	:= $(addprefix $(STRUCT_MANAGE_DIR)/, $(STRUCT_MANAGE_SRCS))

RAYCAST_DIR			:= raycast
RAYCAST_SRCS		:= raycast.c raycast_util1.c raycast_util2.c \
					   raycast_util3.c calculate_texture.c
RAYCAST_SRCS		:= $(addprefix $(RAYCAST_DIR)/, $(RAYCAST_SRCS))

MLX_EVENT_DIR		:= mlx_event
MLX_EVENT_SRCS		:= key_press_handler.c handle_move_keycode.c \
					   handle_turn_keycode.c button_press_handler.c \
					   event_util.c
MLX_EVENT_SRCS		:= $(addprefix $(MLX_EVENT_DIR)/, $(MLX_EVENT_SRCS))

MINIMAP_DIR			:= minimap
MINIMAP_SRCS		:= minimap.c draw_minimap_wall.c minimap_util.c
MINIMAP_SRCS		:= $(addprefix $(MINIMAP_DIR)/, $(MINIMAP_SRCS))

SRCS				:= main.c utils.c $(STRUCT_MANAGE_SRCS) $(PARSER_SRCS) \
					   $(MLX_EVENT_SRCS) $(RAYCAST_SRCS) $(MINIMAP_SRCS)
OBJS				:= $(SRCS:.c=.o)

INCLUDE				:= .
INCLUDE_FILES		:= cub3d.h map.h
INCLUDE_FILES		:= $(addprefix $(INCLUDE)/, $(INCLUDE_FILES))

CC					:= cc
CFLAGS				:= -g -Wall -Wextra -Werror
RM					:= rm -f

.PHONY				: all
all					: $(NAME)

$(NAME)				: $(OBJS) $(LIBFT) $(LIBMLX) $(INCLUDE_FILES)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) -o $@

%.o					: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE) -I$(LIBMLX_INCLUDE) -I$(INCLUDE) \
	-c $< -o $@

$(LIBFT)			:
	make -C $(LIBFT_DIR) all

$(LIBMLX)			:
	make -C $(LIBMLX_DIR) all
	cp $(LIBMLX_DIR)/$(LIBMLX) ./

.PHONY				: clean
clean				:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

.PHONY				: fclean
fclean				: clean
	$(RM) $(NAME) $(LIBMLX)
	make -C $(LIBFT_DIR) fclean
	# make -C $(LIBMLX_DIR) clean

.PHONY				: re
re					: fclean all
