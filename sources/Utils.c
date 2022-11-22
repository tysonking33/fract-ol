/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:30 by tytang            #+#    #+#             */
/*   Updated: 2022/11/21 13:43:50 by tytang           ###   ########.fr       */
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

int check_type(t_fractol *frac, char *type)
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
}

void display_instructions(t_fractol *frac)
{

	if (frac->var.frac_type == 0)
		ft_putstr_fd("invalid syntax");
	else if (frac->var.frac_type >= 1)
	{
		ft_putstr_fd("current_fractol:");
		ft_putstr_fd(frac->var.frac_name);
	}

	//insert instructions

}

void draw(t_fractol *frac, int x_coord, int y_coord, int colour)
{
	int pixel;

	if (frac->img.bits_per_pxl != 32)
		colour = mlx_get_color_value(frac->mlx.init, colour);
	pixel = ((y_coord * frac->img.line_size) + x_coord * 4);
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