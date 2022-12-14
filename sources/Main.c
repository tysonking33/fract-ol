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
		frac->var.frac_type = check_type(argv[1]);
		if (frac->var.frac_type == 0)
		{
			display_instructions(argv[1], frac->var.frac_type);		
