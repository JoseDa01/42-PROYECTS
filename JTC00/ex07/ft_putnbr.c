/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:05:12 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/18 13:36:25 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char aux;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
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
