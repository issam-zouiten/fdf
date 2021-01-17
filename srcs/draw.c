/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 06:15:35 by izouiten          #+#    #+#             */
/*   Updated: 2019/11/12 02:53:55 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		coord_x(t_fdf *fdf, int x, int y)
{
	if (fdf->px == 0)
		return (fdf->startx - (fdf->px * y) + (fdf->scalx * x));
	return (fdf->startx + (((x + y) *
cos(30 * (M_PI / 180))) * fdf->scalx));
}

int		coord_y(t_fdf *fdf, int x, int y, int z)
{
	if (fdf->py == 0)
	{
		return (fdf->starty + ((fdf->py) * x) + ((fdf->scaly) * y) -
		(z * fdf->a));
	}
	return (fdf->starty - ((((x - y) *
	sin(30 * (M_PI / 180))) + (z * fdf->a)) * fdf->scaly));
}

void	draw_y(t_fdf *fdf)
{
	int			i;
	int			j;

	print_menu(fdf);
	i = 0;
	while (i < fdf->nbr_line)
	{
		j = 0;
		while (j < (fdf->nbr_split - 1))
		{
			fdf->clr1 = (fdf->nbr[i][j] != 0) ? 1 : 0;
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->nbr[i][j]);
			j++;
			fdf->x2 = coord_x(fdf, j, i);
			fdf->y2 = coord_y(fdf, j, i, fdf->nbr[i][j]);
			fdf->clr = (fdf->nbr[i][j] != 0) ? 1 : 0;
			bh_dispatch(fdf);
		}
		i++;
	}
}

void	draw_x(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	while (i < (fdf->nbr_line - 1))
	{
		j = 0;
		while (j < fdf->nbr_split)
		{
			fdf->clr1 = (fdf->nbr[i][j] != 0) ? 1 : 0;
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->nbr[i][j]);
			fdf->x2 = coord_x(fdf, j, i + 1);
			fdf->y2 = coord_y(fdf, j, i + 1, fdf->nbr[i + 1][j]);
			fdf->clr = (fdf->nbr[i + 1][j] != 0) ? 1 : 0;
			bh_dispatch(fdf);
			j++;
		}
		i++;
	}
}
