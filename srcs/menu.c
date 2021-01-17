/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 04:13:13 by izouiten          #+#    #+#             */
/*   Updated: 2019/11/12 02:54:44 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf *fdf)
{
	int j;

	j = 0;
	while (++j < fdf->wl)
		mlx_string_put(fdf->mlx, fdf->win, 1500, j, 0xCA32F9, "|");
	j = 0;
	while (++j < fdf->wl)
		mlx_string_put(fdf->mlx, fdf->win, 1910, j, 0xCA32F9, "|");
	menu1(fdf);
}

void	menu1(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 1505, 20,\
	0xCA32F9, "----------------How to Use---------------");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 45, 0xCA32F9, "z-up   : w");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 65, 0xCA32F9, "z-down : z");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 85, 0xCA32F9, "Zoom   : +/-");
	mlx_string_put(fdf->mlx, fdf->win, 1505, 115,\
0xCA32F9, "-----------------------------------------");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 145,\
0xCA32F9, "move :            <- ->");
	mlx_string_put(fdf->mlx, fdf->win, 1720, 131, 0xCA32F9, "^");
	mlx_string_put(fdf->mlx, fdf->win, 1720, 133, 0xCA32F9, "|");
	mlx_string_put(fdf->mlx, fdf->win, 1720, 156, 0xCA32F9, "|");
	mlx_string_put(fdf->mlx, fdf->win, 1720, 159, 0xCA32F9, "v");
	mlx_string_put(fdf->mlx, fdf->win, 1505, 175,\
	0xCA32F9, "-----------------------------------------");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 205,\
	0xCA32F9, "RGB color : blue  -(click)-> b");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 225,\
	0xCA32F9, "            green -(click)-> g");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 245,\
	0xCA32F9, "            red   -(click)-> r");
	mlx_string_put(fdf->mlx, fdf->win, 1505, 275,\
0xCA32F9, "-----------------------------------------");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 305, 0xCA32F9, "ISO       : i");
	mlx_string_put(fdf->mlx, fdf->win, 1520, 335, 0xCA32F9, "parallele : p");
}
