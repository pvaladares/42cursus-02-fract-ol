/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:56:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/29 13:06:55 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

// ======================== DEFINITIONS

// Size of window and images
# define WIDTH		480
# define HEIGHT		320

// Title of window
# define TITLE		"42docs - hooks - by pvaladar - July 2022"

// ======================== INCLUDES

# include "mlx/mlx.h" // local installation of MLX library
# include <X11/X.h>
/* For each event type, a corresponding constant name is defined in X11/X.h
   More info about the relationship between Event Mask & Event Type here:
   https://tronche.com/gui/x/xlib/events/processing-overview.html */
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: XK_Escape)
# include <stdio.h> // perror(); NULL definition, printf(), puts()
# include <stdlib.h> // exit()

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
	x_cursor			: x coordinate of the cursor (last save)
	y_cursor			: y coordinate of the cursor (last save)
*/
typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x_cursor_start;
	int		y_cursor_start;
	int		x_cursor_saved;
	int		y_cursor_saved;
}			t_app;

// ======================== PROTOTYPES

// events.c
int		next_frame(t_app *app);

// hooks_config.c
void	configure_hooks(t_app *app);

// hooks_keys_buttons.c
int		hook_action_key_pressed_released(int keycode, t_app *app);
int		hook_action_key_pressed(int keycode, t_app *app);
int		hook_action_button_pressed(int button, int x, int y, t_app *app);

// hooks_window.c
int	hook_action_mouse_moved(int button, int x, int y, t_app *app);

#endif
