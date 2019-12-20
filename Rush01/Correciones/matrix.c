/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <clostao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:13:18 by clostao-          #+#    #+#             */
/*   Updated: 2019/09/15 23:30:29 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

void				clean_matrix(struct s_table *tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab->matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

int					check_col(struct s_table *tab, int coords[2], int v)
{
	int i;

	i = 0;
	while (i != coords[0])
	{
		if (tab->matrix[i][coords[1]] == v)
			return (0);
		i++;
	}
	return (1);
}

int					check_row(struct s_table *tab, int coords[2], int v)
{
	int i;

	i = 0;
	while (i != coords[1])
	{
		if (tab->matrix[coords[0]][i] == v)
			return (0);
		i++;
	}
	return (1);
}
