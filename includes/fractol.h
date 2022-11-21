/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:44:45 by tytang            #+#    #+#             */
/*   Updated: 2022/11/21 14:02:02 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>

typedef struct s_colour
{
	int	red;
	int	green;
	int	blue;
}				t_colour;

typedef struct s_mouse
{
	double	x_axis;
	double	y_axis;
}				t_mouse;

typedef struct s_variable
{
	double	min_i;
	double	max_i;
	double	min_r;
	double	max_r;
	double	kr;
	double	ki;
}				t_variable;

typedef struct s_image
{
	int	colour;
	void	*image;
}				t_image;

typedef struct s_mlx
{
	void	*init;
}				t_mlx;

typedef struct s_fractol
{
	t_colour	clr;
	t_mouse	mouse;
	t_variable	var;
	t_image	img;
	t_mlx	mlx;
}			t_fractol;

#endif
