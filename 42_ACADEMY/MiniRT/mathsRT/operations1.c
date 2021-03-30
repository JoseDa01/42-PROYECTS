/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:21:17 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/29 20:21:45 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double	lowernumber(t_tupla tupla)
{
	int			i;
	double		lower;

	lower = tupla.tupla[0];
	i = 1;
	while (i < tupla.tam)
	{
		if (tupla.tupla[i] < lower && tupla.tupla[i] >= 0)
			lower = tupla.tupla[i];
		i++;
	}
	return (lower);
}

double	absoluto(double abs)
{
	if (abs < 0)
		return (-abs);
	return (abs);
}
