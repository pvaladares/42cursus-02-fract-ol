/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:56:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 23:34:18 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// ======================== DEFINITIONS

// Size of window and images
# define WIDTH		480
# define HEIGHT		320

// Title of window
# define TITLE		"42docs - events - by pvaladar - July 2022"

// For debugging (0 = OFF ; 1 = ON)
# define DEBUG		1
// ======================== INCLUDES

# include <mlx.h> // MLX library
# include <X11/X.h>
/* For each event type, a corresponding constant name is defined in X11/X.h
   More info about the relationship between Event Mask & Event Type here:
   https://tronche.com/gui/x/xlib/events/processing-overview.html */
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: XK_Escape)
# include <stdio.h> // perror(); NULL definition, printf(), puts()
# include <stdlib.h> // exit()
# include <time.h> // time()

// ======================== TYPEDEF and STRUCTURES

/*
	img_ptr				: a pointer to the image instance
	addr			: a pointer to the memory address of the image
	bits_per_pixel	: the number of bits per pixel
					    (set automatically by MiniLibX for the current data address)
						(bpp = 32 = 4 chars * 1 byte/char * 8 bits/byte)
	line_length		: the size of a line times 4 (each pixel has 4 chars, TTRRGGBB)
					    (set automatically by MiniLibX for the current data address)
	endian			: the endian format (https://en.wikipedia.org/wiki/Endianness)
					    (set by MiniLibX for the current data address)
*/
typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

/*
	mlx_ptr				: a pointer to the mlx instance
	win_ptr				: a pointer to the window instance
	img_ptr				: a pointer to the image
*/
typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
	time_t	key_time_pressed;
	char	key_flag_released;
}			t_app;

// ======================== PROTOTYPES

// events.c
int		next_frame(t_app *app);

// hooks_config.c
void	configure_hooks(t_app *app);

// hooks_keys_buttons.c
int		check_key_pressed_not_released(t_app *app);
int		hook_action_key_pressed_released(int keycode, t_app *app);
int		hook_action_key_pressed(int keycode, t_app *app);
int		hook_action_button_pressed(int button, int x, int y, t_app *app);

// hooks_window.c
int		hook_action_x_window_pressed(t_app *app);
int		hook_action_enter_window(int button, int x, int y, t_app *app);
int		hook_action_leave_window(int button, int x, int y, t_app *app);

#endif
