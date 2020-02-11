 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:00:25 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/13 21:13:50 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"

int	ft_atoi(const char *str, t_var *count)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 0;
	count->large = ft_strlen(str);
	while ((str[i] == ' ') || (str[i] == '\t') ||
	(str[i] == '\n') || (str[i] == '\v') ||
	(str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		nbr = nbr * (-1);
	return (nbr);
}
