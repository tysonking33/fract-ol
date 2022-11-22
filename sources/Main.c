/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:06:10 by tytang            #+#    #+#             */
/*   Updated: 2022/11/21 15:02:10 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

void start_frac(t_fractol *frac)
{
	int colour;

	colour = 0;
	draw_fractol(frac, colour);
}

void create_frac(t_fractol *frac)
{
	frac->clr.red = 6;
	frac->clr.green = 8;
	frac->clr.blue = 16;
	frac->mouse.x_axis = (WIDTH / 2);
	frac->mouse.y_axis = (HEIGHT / 2);
	frac->var.min_i = -1.5705;
	frac->var.max_i = 1.4254;
	frac->var.min_r = -2.4492;
	frac->var.max_r = 1.8758;
	frac->var.kr = -0.07732;
	frac->var.ki = -0.6464;
	frac->mlx.init = mlx_init();
	frac->img.colour = 0x0001dd;
	frac->img.image = mlx_new_image(frac->mlx.init, WIDTH, HEIGHT);
}

int main(int argc, char **argv)
{
	t_fractol	*frac;
	
	write(STDOUT_FILENO, "\e[1;1H\e[2J", 12);

	if (argc == 2)
	{
		frac = (t_fractol *)malloc(sizeof(t_fractol));
		create_frac(frac);
		if (!frac)
			error();
		frac->var.frac_type = check_type(frac, argv[1]);
		display_instructions(frac);
		frac->mlx.win = mlx_new_window(frac->mlx.init, WIDTH, HEIGHT, argv[1]);
		frac->img.image = mlx_new_image(frac->mlx.init, WIDTH, HEIGHT);
		frac->img.data = mlx_get_data_addr(frac->img.image, &frac->img.bits_per_pxl, &frac->img.line_size
					, &frac->img.endian);
		start_frac(frac);
		
	}
}


			error();
		frac->var.frac_type = check_type(argv[1]);
		if (frac->var.frac_type == 0)
		{
			display_instructions(argv[1], frac->var.frac_type);		
