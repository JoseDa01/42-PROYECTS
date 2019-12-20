/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:05:42 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/06 13:14:03 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_space(char *str)
{
	int i;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
	{
		return (i);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(char *str)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	sign = 1;
	nbr = 0;
	i = ft_space(str);
	while ((str[i] == '+' || str[i] == '-') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	nbr = nbr * sign;
	return (nbr);
}
