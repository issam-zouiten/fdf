/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 06:15:55 by izouiten          #+#    #+#             */
/*   Updated: 2019/11/12 02:54:38 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	read_file(t_fdf *fdf, int fd)
{
	while (((fdf->wc * 0.3) / fdf->nbr_split) < 1)
		fdf->wc++;
	if (!(fdf->nbr = (int **)malloc(sizeof(int *) * fdf->nbr_line)))
		exit(1);
	while (ft_get_next_line(fd, &(fdf->line)) > 0)
	{
		if (fdf->line)
		{
			fdf->i = 0;
			fdf->line = fdf_to_space(fdf->line, fdf);
			fdf->split = ft_strsplit(fdf->line, ' ');
			if (!(fdf->nbr[fdf->j] = (int *)malloc(sizeof(int) * \
							fdf->nbr_split)))
				exit(1);
			while (fdf->split[fdf->i])
			{
				fdf->nbr[fdf->j][fdf->i] = ft_atoi(fdf->split[fdf->i]);
				(fdf->i)++;
			}
			free_fdf(&fdf);
			(fdf->j)++;
			(fdf->k)++;
		}
	}
}

int		checker(int fd, t_fdf *fdf)
{
	char	*line;
	char	**split;
	int		*lin;
	int		j;

	j = 0;
	if (!(lin = (int *)malloc(sizeof(int) * fdf->nbr_line)))
		exit(1);
	while (ft_get_next_line(fd, &line) > 0)
	{
		line = fdf_to_space(line, fdf);
		split = ft_strsplit(line, ' ');
		lin[j] = ft_count_split(split);
		free(line);
		j++;
	}
	fdf->nbr_split = lin[0];
	j = 0;
	while (++j < fdf->nbr_line)
	{
		if (lin[0] > lin[j])
			return (0);
	}
	close(fd);
	return (1);
}

void	init(t_fdf *fdf)
{
	fdf->j = 0;
	fdf->k = 0;
	fdf->px = 0;
	fdf->py = 0;
	fdf->a = 0;
	fdf->color = 0x3F3F3F;
	fdf->startx = 416;
	fdf->starty = 420;
	fdf->wc = 1920;
	fdf->wl = 1080;
}

void	make1(int fd, char **av, t_fdf *fdf)
{
	ft_count_line(fdf, fd);
	if (fdf->error == -1 || fdf->nbr_line == 0)
	{
		ft_putendl("No such a file or empty file.");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (checker(fd, fdf) && fdf->error == 0)
	{
		fd = open(av[1], O_RDONLY);
		init(fdf);
		while (((fdf->wl * 0.3) / fdf->nbr_line) < 1)
			fdf->wl++;
		read_file(fdf, fd);
		close(fd);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, fdf->wc, fdf->wl, "FdF 1337");
		mlx_expose_hook(fdf->win, get_hook, fdf);
		mlx_hook(fdf->win, 2, 0, key_hook, fdf);
		mlx_loop(fdf->mlx);
		free_2d(&(fdf->nbr), fdf->j);
	}
	else
		ft_putendl("Found wrong line length. Exiting.");
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		make1(fd, av, &fdf);
	}
	else
		ft_putendl("usage /fdf \"file\"");
	return (0);
}
