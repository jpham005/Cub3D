/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:08:40 by jaham             #+#    #+#             */
/*   Updated: 2022/03/14 15:13:37 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_buffer
{
	char			buf[BUFFER_SIZE];
	char			*cur;
	char			*end;
	int				fd;
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_string
{
	char	*str;
	int		size;
	int		len;
}	t_string;

void	lstdel(t_buffer **cur, int fd);
char	*copy_string(t_string *string);
char	*append_string(t_string *string, char c);
char	*init_string(t_string *string);

#endif