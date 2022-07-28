/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:56:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/28 17:38:20 by pvaladar         ###   ########.fr       */
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

// ======================== INCLUDES

# include "mlx/mlx.h" // local installation of MLX library
# include <X11/X.h>
/* For each event type, a corresponding constant name is defined in X11/X.h
   More info about the relationship between Event Mask & Event Type here:
   https://tronche.com/gui/x/xlib/events/processing-overview.html */
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: XK_Escape)
# include <stdio.h> // perror()
# include <stdlib.h> // exit()
# include <unistd.h> // sleep()

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
	//char	*addr;
	/* https://github.com/keuhdall/images_example/blob/master/example.h
	*/
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
//	t_img	*img_ptr;
}			t_app;

/*
typedef struct s_key_pressed_time
{
	int	;
}			t_key_pressed_time;
*/
#endif
