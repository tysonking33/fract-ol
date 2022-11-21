/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:41:30 by tytang            #+#    #+#             */
/*   Updated: 2022/11/21 15:02:07 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
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
