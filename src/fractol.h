/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:36 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/23 23:47:06 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		480
# define HEIGHT		320
//# define KEY_ESC	65307

# include <mlx.h>
# include <X11/X.h> // Definition of X11 input event masks, event names
# include <X11/keysym.h> // Mapping keyboard keys (e.g.: ESC)
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