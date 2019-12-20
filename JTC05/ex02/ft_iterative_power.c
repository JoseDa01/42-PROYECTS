/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:10:25 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/19 20:23:00 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int i;
	int num;

	i = 1;
	num = nb;
	if (power > 0)
	{
		while (i < power)
		{
			nb = nb * num;
			i++;
		}
		return (nb);
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
