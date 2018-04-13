/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:58:23 by ltran             #+#    #+#             */
/*   Updated: 2017/04/20 13:58:31 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 666

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_x_et_y				t_x;
typedef struct s_coordonnees		t_c;

struct		s_x_et_y
{
	int		x;
	int		y;
};

struct		s_coordonnees
{
	int		last_or_not;
	t_x		a;
	t_x		b;
	t_x		c;
	char	name;
};

void		ft_putstr(char *str);
int			ft_verif(char *buf, int rd, int nb_tetris, int i_tab);
t_c			*create_struct(char *tab, int nb_tetris, int index, int create);
char		**ft_grid(char **grid, int *lenght, int nb_tetri, t_c *tetri);
int			ft_resolve(char **grid, int index, t_c *t, int nb_tetris);

#endif
