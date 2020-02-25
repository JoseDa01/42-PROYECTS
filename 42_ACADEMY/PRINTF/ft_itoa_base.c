/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:08:03 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/25 20:35:00 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftprintf.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(unsigned long nbr, int base, char *tab)
{
	char				*str;
	int					size;
	int					flag;
	unsigned long		tmp;

	flag = 0;
	size = 0;
	if (base < 2 || base > 16)
		return (0);
	flag = ((nbr < 0) && (base == 10)) ? 1 : 0;
	tmp = nbr;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(nbr % base)];
		size--;
		nbr /= base;
	}
	return (str);
}
