/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:31:03 by clostao-          #+#    #+#             */
/*   Updated: 2019/09/15 23:36:08 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

void				ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

struct s_requires	str_to_intab_conversor(char *str, struct s_requires *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] >= '0' && str[i] <= '4')
		{
			tab->req[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
		{
			return (*tab);
		}
		i++;
	}
	return (*tab);
}

int					check_rows_and_cols(struct s_table *tab,
int coords[2], int v)
{
	if (check_row(tab, coords, v) == 0)
		return (0);
	if (check_col(tab, coords, v) == 0)
		return (0);
	return (1);
}

struct s_table		*solve_skyscraper(struct s_table *tab, int coords[2],
int v, int requires[16])
{
	if (coords[0] < 0)
	{
		tab->matrix[0][0] = -1;
		return (tab);
	}
	tab->matrix[coords[0]][coords[1]] = v;
	if (check_rows_and_cols(tab, coords, v) == 0)
		return (back_error(tab, coords, v, requires));
	if (check_ext_numbers(tab, coords, requires) == 0)
		return (back_error(tab, coords, v, requires));
	if (coords[0] == 3 && coords[1] == 3)
		return (tab);
	return (go_forward_solving(tab, coords, v, requires));
}

struct	s_table		*back_error(struct s_table *tab, int coords[2],
int v, int requires[16])
{
	while (tab->matrix[coords[0]][coords[1]] == 1)
	{
		tab->matrix[coords[0]][coords[1]] = 0;
		go_the_back_position(&coords[0], &coords[1]);
	}
	v = tab->matrix[coords[0]][coords[1]] - 1;
	return (solve_skyscraper(tab, coords, v, requires));
}
