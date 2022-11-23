/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:31:48 by tytang            #+#    #+#             */
/*   Updated: 2022/11/23 15:32:03 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

int mouseevent(t_fractol *frac, int mouse, int x_coord, int y_coord)
{
    x_coord = 0;
    y_coord = 0;

    if (mouse == SCROLL_UP)
        zoom(frac, 0.8);
    else if (mouse == SCROLL_DOWN)
        zoom(frac, 1.25);
    else if (mouse == LEFT_CLK)
        frac->img.colour = frac->img.colour * 2;
    else if (mouse ==  RIGHT_CLK)
        frac->img.colour = frac->img.colour / 2;
    else if (mouse ==  MIDDLE_CLK)
        frac->img.colour = frac->img.colour + 0x777777;
    start_frac(frac);
    return(1);
}

void zoom(t_fractol *frac, double multi)
{
    frac->var.min_r = frac->var.max_r + multi * (frac->var.min_r - frac->var.max_r);
    frac->var.max_r = frac->var.max_r + multi * ((frac->var.min_r - frac->var.max_r) - multi
            * (frac->var.min_r - frac->var.max_r)) / 2;
    frac->var.min_i = frac->var.max_i + multi * (frac->var.min_i - frac->var.max_i);
    frac->var.max_i = frac->var.max_i + multi * ((frac->var.min_i - frac->var.max_i) - multi
            * (frac->var.min_i - frac->var.max_i)) / 2;
}

int	keyevent(t_fractol *frac, int key)
{
	if ((key == KEY_ANSI_W) || (key == KEY_ANSI_A) || (key == KEY_ANSI_S) || 
        (key == KEY_ANSI_D) || (key == KEY_UP) || (key == KEY_LEFT) || 
        (key == KEY_DOWN) || (key == KEY_RIGHT) || (key == KEY_ESCAPE))
		move(frac, key);
	else if (key == KEY_ANSI_Z)
		zoom(frac, 0.95);
	else if (key == KEY_ANSI_X)
		zoom(frac, 1.15);
	else if (key == KEY_ANSI_J)
	{
		frac->var.ki = frac->var.ki * 1.05;
		frac->var.kr = frac->var.kr * 1.018;
	}
	else if (key == KEY_ANSI_K)
	{
		frac->var.ki = frac->var.ki * 0.9;
		frac->var.kr = frac->var.kr * 0.7;
	}
	else if (key == KEY_ANSI_C)
	{
		frac->img.colour = 0xdd0000;
		frac->img.end = 0xffffff;
	}
	start_frac(frac);
	return (1);
}

void	move(t_fractol *frac, int key)
{
	double	dist;

	dist = 0.07;
	if ((key == KEY_ANSI_W) || (key == KEY_UP))
	{
		frac->var.min_i -= (frac->var.max_i - frac->var.min_i) * dist;
		frac->var.max_i -= (frac->var.max_i - frac->var.min_i) * dist;
	}
	else if ((key == KEY_ANSI_S) || (key == KEY_DOWN))
	{
		frac->var.min_i += (frac->var.max_i - frac->var.min_i) * dist;
		frac->var.max_i += (frac->var.max_i - frac->var.min_i) * dist;
	}
	else if ((key == KEY_ANSI_A) || (key == KEY_LEFT))
	{
		frac->var.min_r -= (frac->var.max_r - frac->var.min_r) * dist;
		frac->var.max_r -= (frac->var.max_r - frac->var.min_r) * dist;
	}
	else if ((key == KEY_ANSI_D) || (key == KEY_RIGHT))
	{
		frac->var.min_r += (frac->var.max_r - frac->var.min_r) * dist;
		frac->var.max_r += (frac->var.max_r - frac->var.min_r) * dist;
	}
	else if (key == KEY_ESCAPE)
		exit(0);
}
