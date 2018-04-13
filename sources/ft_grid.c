/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 05:28:11 by agregoir          #+#    #+#             */
/*   Updated: 2017/02/09 14:22:34 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_grid_lenght(int i, t_c *tetri, int nb_tetri, int lenght)
{
	while (i < nb_tetri)
	{
		tetri[i].last_or_not = lenght;
		i++;
	}
}

int		ft_lenght(int *lenght, int nb_tetri)
{
	while ((*lenght * *lenght) < nb_tetri * 4)
		*lenght += 1;
	return (*lenght);
}

char	**ft_grid(char **grid, int *lenght, int nb_tetri, t_c *tetri)
{
	int		i;
	int		j;

	i = -1;
	if (!(*lenght))
		ft_lenght(lenght, nb_tetri);
	else
		*lenght += 1;
	grid = (char **)malloc(sizeof(char *) * (*lenght + 1));
	while (++i < *lenght)
		grid[i] = (char *)malloc(sizeof(char) * (*lenght + 1));
	grid[i] = 0;
	i = -1;
	j = -1;
	while (grid[++i])
	{
		while (++j < *lenght)
			grid[i][j] = '.';
		grid[i][j] = '\0';
		j = -1;
	}
	ft_put_grid_lenght(0, tetri, nb_tetri, *lenght);
	return (grid);
}
