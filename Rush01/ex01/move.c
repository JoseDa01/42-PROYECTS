/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:13:18 by clostao-          #+#    #+#             */
/*   Updated: 2019/09/16 11:30:47 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"
#include <stdio.h>

void				ft_putnbr(int nb)
{
	char aux;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else if (nb <= 9)
	{
		aux = nb + '0';
		write(1, &aux, 1);
	}
	else
	{
		aux = (nb % 10) + '0';
		nb = nb / 10;
		ft_putnbr(nb);
		write(1, &aux, 1);
	}
}

void				go_the_back_position(int *i, int *j)
{
	if (*j == 0)
	{
		(*j) = 3;
		(*i)--;
	}
	else
	{
		(*j)--;
	}
}

struct	s_table		*go_forward_solving(struct s_table *tab,
		int coords[2], int v, int requires[])
{
	v = 1;
	if (coords[0] <= 3)
	{
		if (coords[1] < 3)
			coords[1]++;
		else
		{
			coords[1] = 0;
			coords[0]++;
		}
	}
	return (solve_skyscraper(tab, coords, 4, requires));
}

void				print_matrix(struct s_table *tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(tab->matrix[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
