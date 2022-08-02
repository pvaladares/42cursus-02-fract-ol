/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:36 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/02 14:44:00 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// ======================== DEFINITIONS

// Size of window and images
# define WIDTH		1000
# define HEIGHT		1000

// Title of window
# define TITLE		"fract-ol by pvaladar"

// Debug variable: ON = 1 / OFF = 0
# ifndef DEBUG
#  define DEBUG		0
# endif

// Maximum number of iterations
#define NMAX		256

// ======================== INCLUDES

# include "minilibx-linux/mlx.h"
//# include <mlx.h> // MLX library
# include <X11/X.h>
/* For each event type, a corresponding constant name is defined in X11/X.h
   More info about the relationship between Event Mask & Event Type here:
   https://tronche.com/gui/x/xlib/events/processing-overview.html */
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: XK_Escape)
# include <stdio.h> // perror()
# include <stdlib.h> // exit()
# include <math.h> // hypot() pow()

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
	double 	re_min;
	double 	re_max;
	double 	im_max;
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
	long double	re;
	long double	im;
}			t_complex;



/*

re_min Represent the interval [re_min, re_max] which is displayed horizontally
re_max

im_min Represent the interval [im_min, im_max] which is displayed vertically
im_max

re_delta The size of the view in the real and imaginary axis (re_delta = re_max - re_min)
im_delta

NMAX The number of iterations before concluding that a complex number is part of the a set

Pixel(x, y) The pixel at coordinates x and y, where x is in [0, WIDTH] and y is in [0, HEIGHT]

P(x = 0, y = 0) corresponds to [re_min, im_max]
*/

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
void	configure_hooks(t_app *app, t_img *img);

// hooks_actions.c
int		close_app(t_app *app);
int	handle_mouse(int button, int x, int y, t_img *img);
int		handle_keys(int keycode, t_app *app);

// init.c
void	fractol_init(t_app *app, t_img *img);
int		exit_program(void);

void	create_mandelbrot(t_img *img);
void	create_julia(t_img *img);



t_complex	complex_pow2(t_complex z);
t_complex	complex_add(t_complex z1, t_complex z2);
long double	complex_norm(t_complex z);

int	color_bernstein_polynomials(double t);

#endif
