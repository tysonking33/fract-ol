/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:30 by tytang            #+#    #+#             */
/*   Updated: 2022/11/28 14:32:26 by tytang           ###   ########.fr       */
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
	else if ((type[0] == 'b') || (type[0] == 'B'))
		return (3);
	else if ((type[0] == 't') || (type[0] == 'T'))
		return (4);
	else
		return (0);
}

int	display_instructions(void *param)
{
	int	counter;

	counter = 0;
	param = NULL;
	while (++counter < 10)
		ft_putstr_fd("           ", 1);
	ft_putstr_fd("		To create a fractol: ./fractol <fractol_name>	", 1);
	ft_putstr_fd("		available fractols: Mandelbrot, Julia", 1);
	ft_putstr_fd("		zoom in: SCROLL DOWN OR x", 1);
	ft_putstr_fd("		zoom out: SCROLL UP OR z", 1);
	ft_putstr_fd("		move: W,A,S,D OR, Up, Down, Left and Right keys", 1);
	ft_putstr_fd("		chang colours: Left/RIGHT/MIDDLE mouse click", 1);
	exit(0);
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

double	abs_dbl(double value)
{
	if (value < 0)
		value = value - (2 * value);
	return (value);
}
