/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 06:15:26 by izouiten          #+#    #+#             */
/*   Updated: 2019/11/12 02:53:45 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bh_dispatch(t_fdf *fdf)
{
	fdf->dx = fdf->x2 - fdf->x1;
	fdf->dy = fdf->y2 - fdf->y1;
	fdf->dx = abs(fdf->dx);
	fdf->dy = abs(fdf->dy);
	fdf->incx = (fdf->x2 > fdf->x1) ? 1 : -1;
	fdf->incy = (fdf->y2 > fdf->y1) ? 1 : -1;
	if (fdf->dx > fdf->dy)
		m_neg(fdf);
	else
		m_pos(fdf);
}

void	m_neg(t_fdf *f)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	(f->clr1 == 1) || (f->clr == 1) ? mlx_pixel_put(f->mlx, f->win,
f->x1, f->y1, f->color) : mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, 0xFFFFFF);
	e = (2 * f->dy) - f->dx;
	inc1 = 2 * (f->dy - f->dx);
	inc2 = 2 * f->dy;
	while (i < f->dx)
	{
		if (e >= 0)
		{
			f->y1 = f->y1 + f->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		f->x1 = f->x1 + f->incx;
		(f->clr1 == 1) || (f->clr == 1) ? mlx_pixel_put(f->mlx, f->win,
f->x1, f->y1, f->color) : mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, 0xFFFFFF);
		i++;
	}
}

void	m_pos(t_fdf *f)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	(f->clr1 == 1) || (f->clr == 1) ? mlx_pixel_put(f->mlx, f->win,
f->x1, f->y1, f->color) : mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, 0xFFFFFF);
	e = (2 * f->dx) - f->dy;
	inc1 = 2 * (f->dx - f->dy);
	inc2 = 2 * f->dx;
	while (i < f->dy)
	{
		if (e >= 0)
		{
			f->x1 = f->x1 + f->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		f->y1 = f->y1 + f->incy;
		(f->clr1 == 1) || (f->clr == 1) ? mlx_pixel_put(f->mlx, f->win,
f->x1, f->y1, f->color) : mlx_pixel_put(f->mlx, f->win, f->x1, f->y1, 0xFFFFFF);
		i++;
	}
}
