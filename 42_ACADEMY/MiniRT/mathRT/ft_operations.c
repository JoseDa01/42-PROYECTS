/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:44:42 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 13:31:34 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

t_tupla				notableproduct(double a, double b)
{
	t_tupla		result;

	result.tamaño = 3;
	result.tupla[0] = pow(a, 2);
	result.tupla[1] = a * b * 2;
	result.tupla[2] = pow(b, 2);
	return (result);
}

t_tupla				addtupla(t_tupla a, t_tupla b)
{
	t_tupla result;
	int i;

	i = 0;
	if (a.tamaño > b.tamaño)
		result.tamaño = a.tamaño;
	else
		result.tamaño = b.tamaño;
	while (i < 3)
	{
		result.tupla[i] = a.tupla[i] + b.tupla[i];
		i++;
	}
	return (result);
}

t_tupla			multupla(t_tupla tupla, double number)
{
	t_tupla		mul;
	int			i;

	mul.tamaño = tupla.tamaño;
	i = 0;
	while (i < tupla.tamaño)
	{
		mul.tupla[i] = tupla.tupla[i] * number;
		i++;
	}
	return (mul);
}

t_tupla			newtupla(double first, double second)
{
	t_tupla tupla;

	tupla.tamaño = 2;
	tupla.tupla[0] = first;
	tupla.tupla[1] = second;
	return (tupla);
}

double			lowernumber(t_tupla tupla)
{
	int			i;
	double		lower;

	lower = tupla.tupla[0];
	i = 1;
	while (i < tupla.tamaño)
	{
		if (tupla.tupla[i] < lower && tupla.tupla[i] >= 0)
			lower = tupla.tupla[i];
		i++;
	}
	return (lower);
}

double			absoluto(double abs)
{
	if (abs < 0)
		return (-abs);
	return (abs);
}
