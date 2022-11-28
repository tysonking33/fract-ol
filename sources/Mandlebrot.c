/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:56:14 by tytang            #+#    #+#             */
/*   Updated: 2022/11/28 14:31:50 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

int	find_colour(t_fractol *frac, double real_z, double img_z)
{
	if (frac->var.frac_type == 1)
		return (mandelbrot(frac, real_z, img_z));
	else if (frac->var.frac_type == 2)
		return (julia(frac, real_z, img_z));
	else if (frac->var.frac_type == 3)
		return (burning_ship(frac, real_z, img_z));
	return (0);
}

void	draw_fractol(t_fractol *frac, int colour)
{
	int		x_coord;
	int		y_coord;
	double	img_z;
	double	real_z;

	y_coord = -1;
	while (++y_coord < HEIGHT)
	{
		x_coord = -1;
		while (++x_coord < WIDTH)
		{
			real_z = frac->var.min_r + (double)x_coord
				* (frac->var.max_r - frac->var.min_r) / WIDTH;
			img_z = frac->var.min_i + (double)y_coord
				* (frac->var.max_i - frac->var.min_i) / HEIGHT;
			colour = find_colour(frac, real_z, img_z);
			draw(frac, x_coord, y_coord, colour);
		}
	}
	mlx_put_image_to_window(frac->mlx.init,
		frac->mlx.win, frac->img.image, 0, 0);
}

int	mandelbrot(t_fractol *frac, double real_z, double img_z)
{
	int		iter_ctr;
	double	real_c;
	double	img_c;
	double	temp_img_c;
	int		in_set;

	iter_ctr = -1;
	real_c = 0;
	img_c = 0;
	in_set = 1;
	while (++iter_ctr < MAX_ITERATIONS)
	{
		if ((real_c * real_c + img_c * img_c) > 4.0)
		{
			in_set = 0;
			break ;
		}
		temp_img_c = 2 * real_c * img_c + img_z;
		real_c = real_c * real_c - img_c * img_c + real_z;
		img_c = temp_img_c;
	}
	if (in_set == 1)
		return (frac->img.end);
	return (((frac->img.colour - frac->img.end)
			* iter_ctr / MAX_ITERATIONS) + frac->img.end);
}

int	julia(t_fractol *frac, double real_z, double img_z)
{
	int		iter_ctr;
	double	temp_img_z;
	int		in_set;

	iter_ctr = -1;
	in_set = 1;
	while (++iter_ctr < MAX_ITERATIONS)
	{
		if ((real_z * real_z + img_z * img_z) > 4.0)
		{
			in_set = 0;
			break ;
		}
		temp_img_z = 2 * real_z * img_z + frac->var.ki;
		real_z = real_z * real_z - img_z * img_z + frac->var.kr;
		img_z = temp_img_z;
	}
	if (in_set == 1)
		return (frac->img.end);
	return (((frac->img.colour - frac->img.end)
			* iter_ctr / MAX_ITERATIONS) + frac->img.end);
}

int	burning_ship(t_fractol *frac, double real_z, double img_z)
{
	double	real_c;
	double	img_c;
	double	temp_img_c;

	frac->iter_ctr = -1;
	real_c = 0;
	img_c = 0;
	frac->in_set = 1;
	while (++frac->iter_ctr < MAX_ITERATIONS)
	{
		if ((real_c * real_c + img_c * img_c) > 4.0)
		{
			frac->in_set = 0;
			break ;
		}
		temp_img_c = 2 * real_c * img_c + img_z;
		temp_img_c = abs_dbl(temp_img_c);
		real_c = real_c * real_c - img_c * img_c + real_z;
		real_c = abs_dbl(real_c);
		img_c = temp_img_c;
	}
	if (frac->in_set == 1)
		return (frac->img.end);
	return (((frac->img.colour - frac->img.end)
			* frac->iter_ctr / MAX_ITERATIONS) + frac->img.end);
}
