/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:52:46 by jaham             #+#    #+#             */
/*   Updated: 2022/04/16 10:56:08 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

void	exit_message(char *err_str, t_exit_status status)
{
	ft_putstr_fd(err_str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(status);
}
