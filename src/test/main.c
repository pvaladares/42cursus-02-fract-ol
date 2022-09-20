/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:13:37 by pvaladar          #+#    #+#             */
/*   Updated: 2022/09/20 15:52:23 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 This function returns a pointer to a structure that contains all the data
 required throughout the program
*/
t_app	*info(void)
{
	static t_app	info;

	return (&info);
}

/*
 This is the main function of the program, and modules are called
*/
int	main(void)
{
	create_mlx();
	initialize_variables();
	draw();
	//display_text();
	/* Hooks */
	hooks();

	/* End Hooks */
	mlx_loop(info()->mlx_ptr);
	return (0);
}
