/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 06:13:42 by izouiten          #+#    #+#             */
/*   Updated: 2019/10/25 06:13:45 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				**nbr;
	int				nbr_line;
	int				nbr_split;
	float			scalx;
	float			scaly;
	int				px;
	int				py;
	int				clr;
	int				clr1;
	int				startx;
	int				x1;
	int				starty;
	char			**split;
	int				y1;
	int				x2;
	int				wc;
	int				wl;
	int				y2;
	int				dx;
	int				dy;
	int				i;
	int				j;
	float			a;
	int				k;
	char			*line;
	int				incx;
	int				error;
	int				color;
	int				incy;
}					t_fdf;

void				init(t_fdf *fdf);
int					ft_count_split(char **split);
char				*fdf_to_space(char *str, t_fdf *fdf);
void				ft_count_line(t_fdf *fdf, int fd);
int					ft_getnbr(char *str);
int					get_hook(t_fdf *fdf);
int					key_hook(int keycode, t_fdf *fdf);
int					coord_x(t_fdf *fdf, int x, int y);
int					coord_y(t_fdf *fdf, int x, int y, int z);
void				draw_y(t_fdf *fdf);
void				draw_x(t_fdf *fdf);
void				bh_dispatch(t_fdf *fdf);
void				m_neg(t_fdf *fdf);
void				m_pos(t_fdf *fdf);
void				read_file(t_fdf *fdf, int fd);
int					checker(int fd, t_fdf *fdf);
void				free_fdf(t_fdf **fdf);
void				make1(int fd, char **av, t_fdf *fdf);
void				free_2d(int ***tab, int size);
void				print_menu(t_fdf *fdf);
void				menu1(t_fdf *fdf);
#endif
