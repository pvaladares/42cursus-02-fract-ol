/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:36 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/30 17:14:52 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// ======================== DEFINITIONS

// Size of window and images
# define WIDTH		480
# define HEIGHT		320

// Title of window
# define TITLE		"fract-ol by pvaladar - July 2022"

// ======================== INCLUDES

# include <mlx.h> // MLX library
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
	t_img	*img_ptr;
}			t_app;

/*
	Take z being a complex number:
		z = a + b*i
	
	Note:
		i = sqrt(-1)
		i * i = -1
	
	More info: https://en.wikipedia.org/wiki/Complex_number

	a	: the real part of the complex number, moving on the x axis (Re)
	b	: the imaginary part (Im) of the complex number, moving on the y axis (Im)
*/
typedef struct s_complex
{
	double	a;
	double	b;
}			t_complex;



// ======================== PROTOTYPES

// colours_1.c
int		colour_get_trgb(int t, int r, int g, int b);
int		colour_get_t(int trgb);
int		colour_get_r(int trgb);
int		colour_get_g(int trgb);
int		colour_get_b(int trgb);

// colours_2.c
int		colour_get_opposite(int trgb);
int		colour_add_shape(double distance, int trgb);

// custom_mlx.c
void	fast_mlx_pixel_put(t_img *img, int x, int y, int color);

// hooks_config.c
void	configure_hooks(t_app *self);

// hooks_actions.c
int		close_app(t_app *self);
int		close_window_cross_window(t_app *self);
int		close_window_esc_key(int keycode, t_app *self);
int		mouse_hook(int button, int x, int y, t_app *self);

// init.c
void	fractol_init(t_app *app, t_img *img);

/*
// fractol.c
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		render_next_frame(t_data img);
//void	show_help(t_app *self);

// hooks.c
int		close_window_cross_window(t_app *self);
int		close_window_esc_key(int keycode, t_app *self);
int		mouse_hook(int button, int x, int y, t_app *self);
void	configure_hooks(t_app *self);
*/
#endif
