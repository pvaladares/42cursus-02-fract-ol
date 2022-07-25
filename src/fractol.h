/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:36 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/25 12:48:08 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		480
# define HEIGHT		320
//# define KEY_ESC	65307

# include "mlx/mlx.h" // MLX

# include <X11/X.h> 
/* Input Event Masks. Used as event-mask window attribute and as arguments
   to Grab requests.  Not to be confused with event names.  */

// Definition of X11 input event names (e.g.: KeyPress),
/* Input Event Masks. Used as event-mask window attribute and as arguments
   to Grab requests. */
					// event masks (e.g.: KeyPressMask)
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: XK_Escape)
# include <stdio.h> // perror()
# include <stdlib.h> // exit()

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif