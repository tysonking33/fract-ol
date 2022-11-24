/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:30 by tytang            #+#    #+#             */
/*   Updated: 2022/11/24 17:02:59 by tytang           ###   ########.fr       */
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

	//while (++counter < 10)
	//	ft_putstr("           ");

	//ft_putstr("			");

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