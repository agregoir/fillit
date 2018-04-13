/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:58:06 by ltran             #+#    #+#             */
/*   Updated: 2017/04/20 13:58:09 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display(int index, char **grid, int lenght)
{
	while (index++ < lenght - 1)
	{
		ft_putstr(grid[index]);
		ft_putstr("\n");
	}
}

int		ft_usage(void)
{
	ft_putstr("usage : fillit input_file\n");
	return (0);
}

int		ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		main_two(t_c *tetri, char **grid, int lenght, int nb_tetris)
{
	grid = ft_grid(grid, &lenght, nb_tetris, tetri);
	while (!(ft_resolve(grid, 0, tetri, nb_tetris)))
		grid = ft_grid(grid, &lenght, nb_tetris, tetri);
	ft_display(-1, grid, lenght);
	return (0);
}

int		main(int argc, char **argv)
{
	t_c		*tetri;
	int		fd;
	int		nb_read_octets;
	char	buf[BUF_SIZE];
	int		nb_tetris;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (ft_usage());
	if (fd == -1)
		return (ft_error());
	nb_read_octets = read(fd, buf, BUF_SIZE);
	buf[nb_read_octets] = '\0';
	nb_tetris = ft_verif(buf, nb_read_octets, 0, 0);
	if (!(nb_tetris))
		return (ft_error());
	else
		tetri = create_struct(buf, nb_tetris, -1, 0);
	return (main_two(tetri, NULL, 0, nb_tetris));
}
