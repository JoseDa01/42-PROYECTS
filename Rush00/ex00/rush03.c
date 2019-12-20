/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:11:34 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/08 12:43:52 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if ((i == 0 && j == 0) || (i == y - 1 && j == 0))
				ft_putchar('A');
			else if ((i == 0 && j == x - 1) || (i == y - 1 && j == x - 1))
				ft_putchar('C');
			else if (j > 0 && j < x - 1 && i > 0 && i < y - 1)
				ft_putchar(' ');
			else
				ft_putchar('B');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}
