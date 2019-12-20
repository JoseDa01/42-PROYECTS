/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:13:18 by clostao-          #+#    #+#             */
/*   Updated: 2019/09/15 23:30:14 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		check_ext_numbers(struct s_table *tab, int coords[2], int requires[16])
{
	if (check_hor_left(tab, coords, requires) == 0)
		return (0);
	if (check_hor_right(tab, coords, requires) == 0 && coords[1] == 3)
		return (0);
	if (check_vert_up(tab, coords, requires) == 0)
		return (0);
	if (check_vert_down(tab, coords, requires) == 0 && coords[0] == 3)
		return (0);
	return (1);
}

int		check_hor_left(struct s_table *tab, int coords[2], int requires[16])
{
	int blocks;
	int max;
	int x;

	x = 0;
	max = 0;
	blocks = 0;
	while (x < 4)
	{
		if (tab->matrix[coords[0]][x] > max)
		{
			max = tab->matrix[coords[0]][x];
			blocks++;
		}
		x++;
	}
	if (blocks > requires[8 + coords[0]]
			|| requires[8 + coords[0]] - blocks > 4 - max)
		return (0);
	return (1);
}

int		check_hor_right(struct s_table *tab, int coords[2], int requires[16])
{
	int blocks;
	int max;
	int x;

	x = 3;
	max = 0;
	blocks = 0;
	while (x > -1)
	{
		if (tab->matrix[coords[0]][x] > max)
		{
			max = tab->matrix[coords[0]][x];
			blocks++;
		}
		x--;
	}
	if (blocks > requires[12 + coords[0]]
			|| requires[12 + coords[0]] - blocks > 4 - max)
		return (0);
	return (1);
}

int		check_vert_up(struct s_table *tab, int coords[2], int requires[16])
{
	int blocks;
	int max;
	int x;

	x = 0;
	max = 0;
	blocks = 0;
	while (x < 4)
	{
		if (tab->matrix[x][coords[1]] > max)
		{
			max = tab->matrix[x][coords[1]];
			blocks++;
		}
		x++;
	}
	if (blocks > requires[coords[1]]
			|| requires[coords[1]] - blocks > 4 - max)
		return (0);
	return (1);
}

int		check_vert_down(struct s_table *tab, int coords[2], int requires[16])
{
	int blocks;
	int max;
	int x;

	x = 3;
	max = 0;
	blocks = 0;
	while (x > -1)
	{
		if (tab->matrix[x][coords[1]] > max)
		{
			max = tab->matrix[x][coords[1]];
			blocks++;
		}
		x--;
	}
	if (blocks > requires[4 + coords[1]]
			|| requires[4 + coords[1]] - blocks > 4 - max)
		return (0);
	return (1);
}
