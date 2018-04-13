/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 08:00:24 by agregoir          #+#    #+#             */
/*   Updated: 2017/02/14 18:46:32 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_enlever_tetri(char **grid, t_c tetri, int i, int j)
{
	while (grid[i] != 0)
	{
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] == tetri.name)
				grid[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_placer_tetri(char **grid, t_c tetri, int i, int j)
{
	grid[i][j] = tetri.name;
	grid[i + tetri.a.x][j + tetri.a.y] = tetri.name;
	grid[i + tetri.b.x][j + tetri.b.y] = tetri.name;
	grid[i + tetri.c.x][j + tetri.c.y] = tetri.name;
}

int		ft_possible(char **grid, t_c tetri, int i, int j)
{
	if ((i + tetri.a.x >= 0
			&& j + tetri.a.y >= 0
			&& i + tetri.b.x >= 0
			&& j + tetri.b.y >= 0
			&& i + tetri.c.x >= 0
			&& j + tetri.c.y >= 0)
			&& (i + tetri.a.x < tetri.last_or_not
			&& j + tetri.a.y < tetri.last_or_not
			&& i + tetri.b.x < tetri.last_or_not
			&& j + tetri.b.y < tetri.last_or_not
			&& i + tetri.c.x < tetri.last_or_not
			&& j + tetri.c.y < tetri.last_or_not)
			&& (grid[i][j] == '.'
			&& grid[i + tetri.a.x][j + tetri.a.y] == '.'
			&& grid[i + tetri.b.x][j + tetri.b.y] == '.'
			&& grid[i + tetri.c.x][j + tetri.c.y] == '.'))
		return (1);
	else
		return (0);
}

int		ft_resolve(char **grid, int index, t_c *t, int nb_tetris)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (index == nb_tetris)
		return (1);
	while (grid[++i] != 0)
	{
		while (grid[i][++j] != 0)
		{
			if ((i == t[1].last_or_not - 1) && (j == t[1].last_or_not - 1))
				return (0);
			if (ft_possible(grid, t[index], i, j))
			{
				ft_placer_tetri(grid, t[index], i, j);
				if (ft_resolve(grid, ++index, t, nb_tetris))
					return (1);
				else
					ft_enlever_tetri(grid, t[--index], 0, 0);
			}
		}
		j = -1;
	}
	return (0);
}
