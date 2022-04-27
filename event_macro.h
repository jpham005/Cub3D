/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_macro.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:45:47 by jaham             #+#    #+#             */
/*   Updated: 2022/04/27 16:28:19 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MACRO_H
# define EVENT_MACRO_H

typedef enum e_keymap		t_keymap;
typedef enum e_rotate_dir	t_rotate_dir;
typedef enum e_event_list	t_event_list;
typedef enum e_event_mask	t_event_mask;

enum e_keymap
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_E = 14,
	KEY_ESC = 53,
	KEY_L_A = 123,
	KEY_R_A = 124,
	MOUSE_CODE = 200,
	MOUSE_L = 1 + MOUSE_CODE,
	MOUSE_R = 2 + MOUSE_CODE
};

enum e_rotate_dir
{
	LEFT = 1,
	RIGHT = 2
};

enum e_event_list
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	DESTROY_NOTIFY = 17
};

enum e_event_mask
{
	KEY_PRESS_MASK = 1L << 0,
	KEY_RELEASE_MASK = 1L << 1,
	BUTTON_PRESS_MASK = 1L << 2,
	DESTROY_NOTIFY_MASK = 1L << 17
};

#endif
