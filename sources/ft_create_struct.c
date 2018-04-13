/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 05:50:45 by agregoir          #+#    #+#             */
/*   Updated: 2017/02/09 14:43:14 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_c	*ft_c(int i, t_c *tetri, int nb_tetris)
{
	while (i < nb_tetris)
	{
		if (tetri[i].c.x == 9)
			tetri[i].c.y = -1;
		if (tetri[i].c.x == 15 || tetri[i].c.x == 10 || tetri[i].c.x == 5)
			tetri[i].c.y = 0;
		if (tetri[i].c.x == 6 || tetri[i].c.x == 11)
			tetri[i].c.y = 1;
		if (tetri[i].c.x == 7)
			tetri[i].c.y = 2;
		if (tetri[i].c.x == 3)
			tetri[i].c.y = 3;
		if (tetri[i].c.x == 3)
			tetri[i].c.x = 0;
		if (tetri[i].c.x == 6 || tetri[i].c.x == 5 || tetri[i].c.x == 7)
			tetri[i].c.x = 1;
		if (tetri[i].c.x == 9 || tetri[i].c.x == 11 || tetri[i].c.x == 10)
			tetri[i].c.x = 2;
		if (tetri[i].c.x == 15)
			tetri[i].c.x = 3;
		i++;
	}
	return (tetri);
}

t_c	*ft_b(int i, t_c *tetri, int nb_tetris)
{
	while (i < nb_tetris)
	{
		if (tetri[i].b.x == 10 || tetri[i].b.x == 5)
			tetri[i].b.y = 0;
		if (tetri[i].b.x == 2)
			tetri[i].b.y = 2;
		if (tetri[i].b.x == 6)
			tetri[i].b.y = 1;
		if (tetri[i].b.x == 9 || tetri[i].b.x == 4)
			tetri[i].b.y = -1;
		if (tetri[i].b.x == 2)
			tetri[i].b.x = 0;
		if (tetri[i].b.x == 5 || tetri[i].b.x == 6 || tetri[i].b.x == 4)
			tetri[i].b.x = 1;
		if (tetri[i].b.x == 10 || tetri[i].b.x == 9)
			tetri[i].b.x = 2;
		i++;
	}
	return (ft_c(0, tetri, nb_tetris));
}

t_c	*ft_a(int i, t_c *tetri, int nb_tetris)
{
	while (i < nb_tetris)
	{
		if (i != nb_tetris - 1)
			tetri[i].last_or_not = 0;
		if (i == nb_tetris - 1)
			tetri[i].last_or_not = 1;
		if (tetri[i].a.y == 5 || tetri[i].a.y == 4 || tetri[i].a.y == 3)
			tetri[i].a.x = 1;
		if (tetri[i].a.y == 1)
			tetri[i].a.x = 0;
		if (tetri[i].a.y == 1)
			tetri[i].a.y = 1;
		if (tetri[i].a.y == 5)
			tetri[i].a.y = 0;
		if (tetri[i].a.y == 4)
			tetri[i].a.y = -1;
		if (tetri[i].a.y == 3)
			tetri[i].a.y = -2;
		i++;
	}
	return (ft_b(0, tetri, nb_tetris));
}

t_c	*create_struct(char *tab, int nb_tetris, int index, int create)
{
	t_c				*tetri;
	int				tmp_index;
	int				nb_diese;

	nb_diese = 0;
	tetri = (t_c *)malloc(sizeof(t_c) * nb_tetris);
	while (tab[++index] != '\0')
	{
		if ((tab[index] == '#') && (nb_diese == 3))
		{
			tetri[create].name = create + 'A';
			tetri[create++].c.x = index - tmp_index;
			nb_diese = -1;
		}
		if (((tab[index] == '#') && (nb_diese == 2)) && (nb_diese++ == 2))
			tetri[create].b.x = index - tmp_index;
		if (((tab[index] == '#') && (nb_diese == 1)) && (nb_diese++ == 1))
			tetri[create].a.y = index - tmp_index;
		if ((tab[index] == '#') && ((nb_diese == -1) || (nb_diese == 0)))
		{
			nb_diese == 0 ? tmp_index = index : tmp_index;
			nb_diese++;
		}
	}
	return (ft_a(0, tetri, create));
}
