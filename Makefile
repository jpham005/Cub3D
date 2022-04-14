# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 22:36:11 by jaham             #+#    #+#              #
#    Updated: 2022/04/14 09:13:11 by jaham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	cub3d

LIBFT_DIR			:=	libft
LIBFT_INCLUDE		:=	$(LIBFT_DIR)
LIBFT				:=	$(LIBFT_DIR)/libft.a

LIBMLX_DIR			:=	minilibx_mms_20210621
LIBMLX_INCLUDE		:=	$(LIBMLX_DIR)
LIBMLX				:=	libmlx.dylib

SRCS				:=	main.c
OBJS				:=	$(SRCS:.c=.o)

CC					:=	cc
CFLAGS				:=	#-Wall -Wextra -Werror -g #fsanitize=address
RM					:=	rm -f

.PHONY				:	all
all					:	$(NAME)

$(NAME)				:	$(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $^ -o $@

%.o					:	%.c
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE) -I$(LIBMLX_INCLUDE) -c $< -o $@

$(LIBFT)			:
	make -C $(LIBFT_DIR) all

$(LIBMLX)			:
	make -C $(LIBMLX_DIR) all
	cp $(LIBMLX_DIR)/$(LIBMLX) ./

.PHONY				:	clean
clean				:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

.PHONY				:	fclean
fclean				:	clean
	$(RM) $(NAME) $(LIBMLX)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) clean

.PHONY				:	re
re					:	fclean all
