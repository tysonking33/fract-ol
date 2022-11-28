/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:06:10 by tytang            #+#    #+#             */
/*   Updated: 2022/11/28 12:26:52 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

void	start_frac(t_fractol *frac)
{
	int	colour;

	colour = 0;
	draw_fractol(frac, colour);
}

void	create_frac(t_fractol *frac)
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
	frac->img.end = 0x000000;
	frac->img.image = mlx_new_image(frac->mlx.init, WIDTH, HEIGHT);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	write(STDOUT_FILENO, "\e[1;1H\e[2J", 12);
	if (argc == 2)
	{
		f = (t_fractol *)malloc(sizeof(t_fractol));
		create_frac(f);
		if (!f)
			error();
		f->var.frac_type = check_type(argv[1]);
		if (!(f->var.frac_type))
			display_instructions(f->mlx.init);
		f->mlx.init = mlx_init();
		f->mlx.win = mlx_new_window(f->mlx.init, WIDTH, HEIGHT, argv[1]);
		f->img.image = mlx_new_image(f->mlx.init, WIDTH, HEIGHT);
		f->img.data = mlx_get_data_addr(f->img.image, &f->img.bits_per_pxl,
				&f->img.line_size, &f->img.endian);
		start_frac(f);
		mlx_hook(f->mlx.win, 4, 3, mouseevent, f);
		mlx_hook(f->mlx.win, 2, 3, keyevent, f);
		mlx_hook(f->mlx.win, 17, 3, display_instructions, f);
		mlx_loop(f->mlx.init);
	}
	f = NULL;
	display_instructions(f);
}
