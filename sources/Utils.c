/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:30 by tytang            #+#    #+#             */
/*   Updated: 2022/11/21 15:02:07 by tytang           ###   ########.fr       */
/*   Updated: 2022/11/24 16:40:39 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

void	error(void)
{
	perror("\033[31mError");
	exit(0);
}

int	check_type(char *type)
{
	if ((type[0] == 'm') || (type[0] == 'M'))
		return (1);
	else if ((type[0] == 'j') || (type[0] == 'J'))
		return (2);
	else
		return (0);
}

int	display_instructions(void *param)
{
	int counter;

	counter = 0;
	param = NULL;
	if (frac->var.frac_type == 0)
		ft_putstr_fd("invalid syntax");
	else if (frac->var.frac_type >= 1)
	{
		ft_putstr_fd("current_fractol:");
		ft_putstr_fd(frac->var.frac_name);
	}
}

int check_type(char *type)
{
	if ((type[0] == 'm') || (type[0] == 'M'))
	{
		frac->var.frac_name = (char *)malloc(11*sizeof(char));
		frac->var.frac_name = "Mandlebrot";
		return 1;
	}
	else if ((type[0] == 'j') || (type[0] == 'J'))
	{
		frac->var.frac_name = (char *)malloc(6*sizeof(char));
		frac->var.frac_name = "Julia";
		return 2;
	}
	else
		return 0;
	return 0;
}

void display_instructions(char * type_name, int type)
{
	if (type == 0)
		ft_putstr("invalid syntax");
	else if (type >= 1)
	{
		ft_putstr("current fractol:");
		ft_putstr(type_name);
	}
	}

void display_instructions(char *type_name, int type )
{

	if (frac->var.frac_type == 0)
		ft_putstr_fd("invalid syntax");
	else if (frac->var.frac_type >= 1)
	{
		ft_putstr_fd("current_fractol");
		ft_putstr_fd();
	}
}

int check_type(char *type)
{
	if ((type[0] == 'm') || (type[0] == 'M'))
		return 1;
	else if ((type[0] == 'j') || (type[0] == 'J'))
		return 2;
	else
		return 0;
	return 0;
}

void display_instructions(char * type_name, int type)
{
	if (type == 0)
		ft_putstr("invalid syntax");
	else if (type >= 1)
	{
		ft_putstr("current fractol:");
		ft_putstr(type_name);
	}
	}

void display_instructions(char *type_name, int type )
{

	if (type == 0)
		ft_putstr_fd("invalid syntax");
	else if (type >= 1)
	{
		ft_putstr_fd("current_fractol");
		ft_putstr_fd();
	}
}

void draw(t_fractol *frac, int x_coord, int y_coord, int colour)
{
	int pixel;
	//insert instructions

	while (++counter < 10)
		ft_putstr("           ");

	ft_putstr("		to run use:  ./fractol <fractol name>	");
	ft_putstr("		current	fractols: Mandelbrot, Julia ");
	ft_putstr("		zoom in: Scroll Down, x	");
	ft_putstr("		zoom out: Scroll UP, z	");
	ft_putstr("		move: A,W,D,S OR Up, Down, Left,Right	");
	t_putstr("		change colour: Left, Right mouse click, OR c	");
	ft_putstr("		exit program: ESC	");



	printf("%p", param);

	exit (0);
}

void	draw(t_fractol *frac, int x_coord, int y_coord, int colour)
{
	int	pixel;

	if (frac->img.bits_per_pxl != 32)
		colour = mlx_get_color_value(frac->mlx.init, colour);
	pixel = ((y_coord * frac->img.line_size) + (x_coord * 4));
	if (frac->img.endian == 1)
	{
		frac->img.data[pixel + 0] = (colour >> 24);
		frac->img.data[pixel + 1] = (colour >> 16) & 0xFF;
		frac->img.data[pixel + 2] = (colour >> 8) & 0xFF;
		frac->img.data[pixel + 3] = (colour) & 0xFF;
	}
	else if (frac->img.endian == 0)
	{
		frac->img.data[pixel + 3] = (colour >> 24);
		frac->img.data[pixel + 2] = (colour >> 16) & 0xFF;
		frac->img.data[pixel + 1] = (colour >> 8) & 0xFF;
		frac->img.data[pixel + 0] = (colour) & 0xFF;
	}
}
