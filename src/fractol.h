/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:36 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/25 17:23:25 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== DEFINITIONS

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		480
# define HEIGHT		320

// ======================== INCLUDES

# include "mlx/mlx.h" // local installation of MLX library
# include <X11/X.h>
/* For each event type, a corresponding constant name is defined in X11/X.h
   More info about the relationship between Event Mask & Event Type here:
   https://tronche.com/gui/x/xlib/events/processing-overview.html */
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: XK_Escape)
# include <stdio.h> // perror()
# include <stdlib.h> // exit()

// ======================== TYPEDEF and STRUCTURES

/*
	mlx				: a pointer to the mlx instance
	win				: a pointer to the window instance
*/
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

/*
	img				: a pointer to the image instance
	addr			: a pointer to the memory address of the image
	bits_per_pixel	: set by MiniLibX for the current data address
	line_length		: set by MiniLibX for the current data address
	endian			: set by MiniLibX for the current data address
*/
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// ======================== PROTOTYPES

#endif
