/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:22:49 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:37:03 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vect3				newvector(double x, double y, double z)
{
	t_vect3 vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vect3				crossproduct(t_vect3 first, t_vect3 second)
{
	t_vect3 result;

	result.x = first.y * second.z - first.z * second.y;
	result.y = first.z * second.x - first.x * second.z;
	result.z = first.x * second.y - first.y * second.x;
	return (result);
}

double				vector_index(t_vect3 vect, int i)
{
	if (i == 0)
		return (vect.x);
	else if (i == 1)
		return (vect.y);
	else if (i == 2)
		return (vect.z);
	return (0);
}

t_vect3				changelenght(t_vect3 vector, double module)
{
	double		moduleoriginal;
	double		factor;

	moduleoriginal = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	factor = moduleoriginal / module;
	vector.x /= factor;
	vector.y /= factor;
	vector.z /= factor;
	return (vector);
}

t_vect3				mulvector(t_vect3 vector, double number)
{
	vector.x *= number;
	vector.y *= number;
	vector.z *= number;
	return (vector);
}
