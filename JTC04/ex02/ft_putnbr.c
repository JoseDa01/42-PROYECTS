/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:56:28 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/19 13:45:31 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
