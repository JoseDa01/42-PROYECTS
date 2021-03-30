/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:47:55 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:07 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char aux;

	if (nb == -2147483648)
	{
		write(fd, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb <= 9)
	{
		aux = nb + '0';
		write(fd, &aux, 1);
	}
	else
	{
		aux = (nb % 10) + '0';
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		write(fd, &aux, 1);
	}
}
