/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:54:48 by agregoir          #+#    #+#             */
/*   Updated: 2017/02/09 11:56:22 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}
