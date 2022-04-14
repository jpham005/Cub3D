# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaham <jaham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 19:20:20 by jaham             #+#    #+#              #
#    Updated: 2022/03/16 19:20:20 by jaham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

CC 		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

SRCS	:=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c get_next_line_utils.c ft_malloc.c ft_free.c

BSRCS	:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJS	:=	$(SRCS:.c=.o)

BOBJS	:=	$(BSRCS:.c=.o)

RM		:=	rm
RMFLAGS	:=	-f

AR		:=	ar
ARFLAGS	:=	rcus

.PHONY	:	all
all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY	:	bonus
bonus	:	$(OBJS) $(BOBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY	:	.c.o
.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY	:	clean
clean	:
	$(RM) $(RMFLAGS) $(OBJS) $(BOBJS)

.PHONY	:	fclean
fclean	:	clean
	$(RM) $(RMFLAGS) $(NAME)

.PHONY	:	re
re		:	fclean all