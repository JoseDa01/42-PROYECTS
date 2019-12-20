/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:28:10 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/19 18:58:10 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int i;
	int a;

	a = 0;
	i = 2;
	if (nb == 2147483647)
		return (1);
	else if (nb > 1)
	{
		while (i <= nb)
		{
			if (nb % i == 0)
				a++;
			i++;
		}
		if (a >= 2)
			return (0);
		else
			return (1);
	}
	else
	{
		return (0);
	}
}
