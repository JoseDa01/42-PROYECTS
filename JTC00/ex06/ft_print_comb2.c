/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 11:03:41 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/08 20:50:31 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	inicializar(char c[5])
{
	c[0] = '0';
	c[1] = '0';
	c[2] = ' ';
	c[3] = '0';
	c[4] = '1';
}

int		next_number(char c[5])
{
	c[4]++;
	if (c[4] == '9' + 1)
	{
		c[3]++;
		c[4] = '0';
	}
	if (c[3] == '9' + 1)
	{
		c[1]++;
		if (c[1] == '9' + 1)
			c[0]++;
		if (c[1] == '9' + 1)
			c[1] = '0';
		c[4] = c[1];
		c[3] = c[0];
		c[4]++;
		if (c[4] == '9' + 1)
			c[3]++;
		if (c[4] == '9' + 1)
			c[4] = '0';
	}
	if (c[0] == '9' && c[1] == '9')
		return (1);
	else
		return (0);
}

void	ft_print_comb2(void)
{
	char	c[5];
	int		fin;

	fin = 0;
	inicializar(c);
	while (fin == 0)
	{
		write(1, c, 5);
		fin = next_number(c);
		if (fin == 0)
		{
			write(1, ", ", 2);
		}
	}
}
