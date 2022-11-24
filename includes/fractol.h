/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:44:45 by tytang            #+#    #+#             */
/*   Updated: 2022/11/24 18:55:09 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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
	int		frac_type;
}				t_variable;

typedef struct s_image
{
	void	*image;
	char	*data;
	int		bits_per_pxl;
	int		line_size;
	int		endian;
	int		end;
	int		colour;
}				t_image;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	char	*data;
}				t_mlx;

typedef struct s_fractol
{
	t_colour	clr;
	t_mouse		mouse;
	t_variable	var;
	t_image		img;
	t_mlx		mlx;
}			t_fractol;

int		main(int argc, char **argv);
void	create_frac(t_fractol *frac);
void	start_frac(t_fractol *frac);
void	error(void);
int		check_type(char *type);
int		display_instructions(void *param);
void	draw(t_fractol *frac, int x_coord, int y_coord, int colour);
int		mouseevent(int mouse, int x_coord, int y_coord, t_fractol *frac);
void	zoom(t_fractol *frac, double multi);
int		keyevent(int key, t_fractol *frac);
void	move(t_fractol *frac, int key);
void	draw_fractol(t_fractol *frac, int colour);
int		mandelbrot(t_fractol *frac, double real_z, double img_z);
int		julia(t_fractol *frac, double real_z, double img_z);

#endif
