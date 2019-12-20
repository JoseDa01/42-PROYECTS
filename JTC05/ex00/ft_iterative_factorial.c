/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:04:29 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/19 21:36:18 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int i;

	if (nb > 12)
		return (0);
	if (nb < 0)
		return (0);
	i = 1;
	while (nb >= 1)
	{
		i = i * nb;
		nb--;
	}
	return (i);
}
