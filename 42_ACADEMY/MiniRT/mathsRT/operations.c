/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:47:51 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 20:21:42 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_tupla	notableproduct(double first, double second)
{
	t_tupla	tupla;

	tupla.tam = 3;
	tupla.tupla[0] = pow(first, 2);
	tupla.tupla[1] = 2 * first * second;
	tupla.tupla[2] = pow(second, 2);
	return (tupla);
}

t_tupla	addtupla(t_tupla first, t_tupla second)
{
	t_tupla		tupla;
	int			i;

	i = 0;
	if (first.tam > second.tam)
		tupla.tam = first.tam;
	else
		tupla.tam = second.tam;
	while (i < 3)
	{
		tupla.tupla[i] = first.tupla[i] + second.tupla[i];
		i++;
	}
	return (tupla);
}

t_tupla	multupla(t_tupla tupla, double number)
{
	t_tupla		mul;
	int			i;

	mul.tam = tupla.tam;
	i = 0;
	while (i < tupla.tam)
	{
		mul.tupla[i] = tupla.tupla[i] * number;
		i++;
	}
	return (mul);
}

t_tupla	newtupla(double first, double second)
{
	t_tupla	tupla;

	tupla.tam = 2;
	tupla.tupla[0] = first;
	tupla.tupla[1] = second;
	return (tupla);
}
