/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:11:34 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/07 20:28:17 by jtello-m         ###   ########.fr       */
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
			if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1))
				ft_putchar('o');
			else if ((i == y - 1 && j == 0) || (i == 0 && j == x - 1))
				ft_putchar('o');
			else if (j > 0 && j < x - 1 && i > 0 && i < y - 1)
				ft_putchar(' ');
			else if (i == 0 || i == y - 1)
				ft_putchar('-');
			else
				ft_putchar('|');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}
