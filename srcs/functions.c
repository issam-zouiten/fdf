/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 06:15:45 by izouiten          #+#    #+#             */
/*   Updated: 2019/11/12 02:54:25 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_count_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	*fdf_clear(char *str, t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		{
			j = i - 1;
			while (str[i] != ' ' && str[i])
			{
				if (str[i + 1] == ' ' || str[i + 1] == '\0')
				{
					while (str[j] && str[i++])
						str[++j] = str[i];
					while (str[j] && !str[i])
						str[++j] = '\0';
				}
				i++;
			}
			fdf_clear(str, fdf);
		}
		i++;
	}
	return (str);
}

char	*fdf_to_space(char *str, t_fdf *fdf)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
			fdf_clear(str + i, fdf);
		if (str[i] && ft_isdigit(str[i]) == 0 && str[i] != ' ')
			fdf->error = -1;
		i++;
	}
	return (str);
}

void	ft_count_line(t_fdf *fdf, int fd)
{
	char	*line;
	int		ret;

	fdf->error = 0;
	fdf->nbr_line = 0;
	while ((ret = ft_get_next_line(fd, &line)) > 0)
	{
		free(line);
		(fdf->nbr_line)++;
	}
	if (ret == -1)
		fdf->error = -1;
	close(fd);
}

void	free_fdf(t_fdf **fdf)
{
	int i;

	free((*fdf)->line);
	i = -1;
	while ((*fdf)->split[++i])
		free((*fdf)->split[i]);
	free((*fdf)->split);
}
