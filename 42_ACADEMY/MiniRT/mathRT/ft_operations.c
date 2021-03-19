/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:44:42 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 13:47:18 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

t_tupla				notableproduct(float a, float b)
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

float				lowernb(t_tupla tupla)
{
	float		lower;
	int			i;

	lower = tupla.tupla[0];
	i = 0;
	while (i < tupla.tamaño)
	{
		if (tupla.tupla[i] < lower && tupla.tupla >= 0)
			lower = tupla.tupla[i];
		i++;
	}
	return (lower);
}