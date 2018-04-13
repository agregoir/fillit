/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 23:33:46 by ltran             #+#    #+#             */
/*   Updated: 2017/02/14 21:08:13 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_links(char *buf, int i_tab, int i, int *nb_links)
{
	if (i <= 4)
	{
		(buf[i_tab + i - 1] == '#') ? ((*nb_links)++) : (*nb_links);
		(buf[i_tab + i + 1] == '#') ? ((*nb_links)++) : (*nb_links);
		(buf[i_tab + i + 5] == '#') ? ((*nb_links)++) : (*nb_links);
	}
	if ((i > 4) && (i <= 14))
	{
		(buf[i_tab + i - 5] == '#') ? ((*nb_links)++) : (*nb_links);
		(buf[i_tab + i - 1] == '#') ? ((*nb_links)++) : (*nb_links);
		(buf[i_tab + i + 1] == '#') ? ((*nb_links)++) : (*nb_links);
		(buf[i_tab + i + 5] == '#') ? ((*nb_links)++) : (*nb_links);
	}
	if ((i > 14) && (i <= 20))
	{
		(buf[i_tab + i - 5] == '#') ? ((*nb_links)++) : (*nb_links);
		(buf[i_tab + i - 1] == '#') ? ((*nb_links)++) : (*nb_links);
		(buf[i_tab + i + 1] == '#') ? ((*nb_links)++) : (*nb_links);
	}
	return (1);
}

int		ft_check_tetri(char *buf, int i_tab, int i, int nb_n)
{
	int		nb_point;
	int		nb_diese;
	int		nb_links;

	nb_point = 0;
	nb_diese = 0;
	nb_links = 0;
	while (++i <= 20)
	{
		if (!((buf[i_tab + i] == '.') || (buf[i_tab + i] == '\n')
			|| (buf[i_tab + i] == '#') || (buf[i_tab + i] == '\0')))
			return (0);
		(buf[i_tab + i] == '.') ? nb_point++ : nb_point;
		((buf[i_tab + i] == '\n') || (buf[i_tab + i] == '\0')) ? nb_n++ : nb_n;
		if (buf[i_tab + i] == '#')
		{
			ft_links(buf, i_tab, i, &nb_links);
			nb_diese++;
		}
	}
	if (((nb_links == 6) || (nb_links == 8)) && (nb_point == 12)
		&& (nb_diese == 4) && (nb_n == 5))
		return (1);
	else
		return (0);
}

int		ft_count_sign(char *buf, int rd, int i, int nb_tetris)
{
	int		nb_point;
	int		nb_diese;
	int		nb_n;

	nb_point = 0;
	nb_diese = 0;
	nb_n = 0;
	while (++i <= rd)
	{
		if (buf[i] == '.')
			nb_point++;
		if (buf[i] == '#')
			nb_diese++;
		if (buf[i] == '\n')
			nb_n++;
	}
	if ((nb_diese == nb_tetris * 4) && (nb_point == (3 * nb_diese))
		&& (nb_n == (nb_diese + nb_tetris - 1)))
		return (nb_tetris);
	else
		return (0);
}

int		ft_verif(char *buf, int rd, int nb_tetris, int i)
{
	nb_tetris = 0;
	i = 0;
	if (((rd != 20) && ((rd - 20) % 21 != 0))
		|| (rd > 545))
		return (0);
	if (rd == 20)
		nb_tetris = 1;
	else
		nb_tetris = (rd - 20) / 21 + 1;
	nb_tetris = ft_count_sign(buf, rd, -1, nb_tetris);
	if (!nb_tetris)
		return (0);
	while (buf[i] != '\0')
	{
		if (!((buf[i + 4] == '\n') && (buf[i + 9] == '\n')
			&& (buf[i + 14] == '\n') && (buf[i + 19] == '\n')
			&& ((buf[i + 20] == '\n') || (buf[i + 20] == '\0'))))
			return (0);
		if (!(ft_check_tetri(buf, i, -1, 0)))
			return (0);
		i = i + 21;
	}
	return (nb_tetris);
}
