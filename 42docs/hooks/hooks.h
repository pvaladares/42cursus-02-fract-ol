/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:19:11 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/03 13:32:36 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

// ======================== DEFINITIONS

// Size of window and images
# define WIDTH		480
# define HEIGHT		320

// Title of window
# define TITLE		"42docs - hooks - by pvaladar - August 2022"

// For debugging (0 = OFF ; 1 = ON)
# define DEBUG		0

// ======================== INCLUDES

# include "minilibx-linux/mlx.h" // include local MLX library
# include <X11/X.h>
/* For each event type, a corresponding constant name is defined in X11/X.h
   More info about the relationship between Event Mask & Event Type here:
   https://tronche.com/gui/x/xlib/events/processing-overview.html */
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: XK_Escape)
# include <stdio.h> // perror(); NULL definition, printf(), puts()
# include <stdlib.h> // exit()
# include <math.h> // atan()

// ======================== TYPEDEF and STRUCTURES

/*
	mlx_ptr			: a pointer to the mlx instance
	win_ptr			: a pointer to the window instance
	img_ptr			: a pointer to the image instance
	img_addr		: a pointer to the memory address of the image
	bits_per_pixel	: the number of bits per pixel
					(set automatically by MiniLibX for the current data address)
					(bpp = 32 = 4 chars * 1 byte/char * 8 bits/byte)
	line_length		: the size of a line times 4 (each pixel has 4 chars, TTRRGGBB)
					(set automatically by MiniLibX for the current data address)
	endian			: the endian format (https://en.wikipedia.org/wiki/Endianness)
					(set by MiniLibX for the current data address)
*/
typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_app;

// ======================== PROTOTYPES

// Events
int	cursor_moved(int x, int y, t_app *app);
int	key_released(int keycode, t_app *app);
int	mouse_button_pressed(int button, int x, int y, t_app *app);

#endif
