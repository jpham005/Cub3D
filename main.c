/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:38:28 by jaham             #+#    #+#             */
/*   Updated: 2022/04/17 13:54:23 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_context	context;

	if (argc != 2)
		exit_message(ARG_ERR_MESSAGE, EXIT_FATAL);
	init_context(&context, argv[1]);
	practice(&context);
}
