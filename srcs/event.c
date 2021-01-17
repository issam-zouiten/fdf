/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 03:30:01 by izouiten          #+#    #+#             */
/*   Updated: 2019/11/12 02:54:15 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_hook(t_fdf *fdf)
{
	fdf->scalx = (fdf->wc * 0.3) / fdf->nbr_split;
	fdf->scaly = (fdf->wl * 0.3) / fdf->nbr_line;
	draw_y(fdf);
	draw_x(fdf);
	return (1);
}

void	key_hook_1(int keycode, t_fdf *fdf)
{
	(keycode == 53) ? exit(1) : 1;
	if (keycode == 78 && fdf->scalx > 1 && fdf->scaly > 1)
	{
		fdf->scalx -= 1;
		fdf->scaly -= 1;
	}
	else if (keycode == 69)
	{
		fdf->scalx += 1;
		fdf->scaly += 1;
	}
	(keycode == 124) && (fdf->startx += 10);
	(keycode == 123) && (fdf->startx -= 10);
	(keycode == 126) && (fdf->starty -= 10);
	(keycode == 125) && (fdf->starty += 10);
	(keycode == 13) && (fdf->a += 0.2);
	(keycode == 6) && (fdf->a -= 0.2);
	(keycode == 46) && (fdf->color += 100000);
	(keycode == 15) && (fdf->color = 0xFF0000);
	(keycode == 5) && (fdf->color = 0x00FF00);
	(keycode == 11) && (fdf->color = 0x0000FF);
}

int		key_hook(int keycode, t_fdf *fdf)
{
	key_hook_1(keycode, fdf);
	if (keycode == 34)
	{
		fdf->startx = 400;
		fdf->starty = 586;
		fdf->px = 1;
		fdf->py = 1;
		fdf->a = 0.2;
	}
	else if (keycode == 35)
	{
		fdf->startx = 400;
		fdf->starty = 420;
		fdf->px = 0;
		fdf->py = 0;
		fdf->a = 0;
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_y(fdf);
	draw_x(fdf);
	return (0);
}

void	free_2d(int ***tab, int size)
{
	int i;

	i = -1;
	while (++i < size)
		free((*tab)[i]);
	free((*tab));
}
