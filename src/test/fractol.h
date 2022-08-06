/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:36 by pvaladar          #+#    #+#             */
/*   Updated: 2022/08/06 02:27:47 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// ======================== DEFINITIONS

// Size of window and images
# define HEIGHT			600
# define WIDTH			600
# define MENU_WIDTH		400

// Title of window
# define TITLE		"fract-ol by pvaladar"

// Debug variable: ON = 1 / OFF = 0
# ifndef DEBUG
#  define DEBUG			0
# endif

// Maximum number of iterations
# define MAX_ITERATIONS	100

// Colors
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLUE			0x000000FF
# define WHITE			0x00FFFFFF
# define BLACK			0

# define MANDELBROT		"Mandelbrot"
// ======================== INCLUDES

# include "minilibx-linux/mlx.h" // include local MLX library
# include <X11/X.h> // definition of all X events and masks
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
	double	re_min;
	double	re_max;
	double	re_delta;
	double	im_min;
	double	im_max;
	double	im_delta;
	double	x_ratio;
	double	y_ratio;
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
	void	*img_ptr;
	int		*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	re_min;
	double	re_max;
	double	re_delta;
	double	im_min;
	double	im_max;
	double	im_delta;
	double	x_ratio;
	double	y_ratio;
	int		max_iterations;
	char	fractal_id;

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
	double	re;
	double	im;
}			t_complex;

typedef struct s_pixel
{
	int		x;
	int		y;
}				t_pixel;

/*

re_min Represent the interval [re_min, re_max] which is displayed horizontally
re_max

im_min Represent the interval [im_min, im_max] which is displayed vertically
im_max
0x00FF0000
Pixel(x, y) The pixel at coordinates x and y, where x is in [0, WIDTH] and y is in [0, HEIGHT]

P(x = 0, y = 0) corresponds to [re_min, im_max]
*/

// ======================== PROTOTYPES

t_app	*info(void);
void	fast_mlx_pixel_put(int x, int y, int color);
void	initialize_variables();
int		mouse_pressed(int button, int x, int y);
int		safe_quit();
int		key_released(int keycode);
int		fractal_mandelbrot(int x, int y);
void	draw(void);

t_complex	complex_pow2(t_complex z);
t_complex	complex_add(t_complex z1, t_complex z2);
double		complex_norm(t_complex z);
void	create_mlx(void);

// Colors
int	color_get_trgb(int t, int r, int g, int b);
int	color_get_t(int trgb);
int	color_get_r(int trgb);
int	color_get_g(int trgb);
int	color_get_b(int trgb);
int	color_get_opposite(int trgb);
int	color_add_shape(double distance, int trgb);
int	color_bernstein_polynomials1(double t);
int	color_bernstein_polynomials2(double t);
int	color_bernstein_polynomials3(double t);
void set_color(int x, int y, int i);
void	display_text(void);
int	mouse_moved(int x, int y);
void	zoom_in(int x, int y);
void	center(int x, int y);

void	hooks(void);
t_complex	pixel2complex(int x, int y);






char	*ft_itoa(int nbr);

#endif
