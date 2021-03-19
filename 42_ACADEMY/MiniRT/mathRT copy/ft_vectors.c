/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:59:22 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/11 12:57:53 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

t_vector			addvect(t_vector vect1, t_vector vect2)
{
	t_vector vectorres;

	vectorres.x = vect1.x + vect2.x;
	vectorres.y = vect1.y + vect2.x;
	vectorres.z = vect1.z + vect2.z;
	return(vectorres);
}

t_vector			multvect(t_vector vector, float nb)
{
	vector.x *= nb;
	vector.y *= nb;
	vector.z *= nb;
	return(vector);
}

t_vector			pointray(t_ray ray, float dist)
{
	t_vector pt;

	pt.x = ray.originpt.x + dist * ray.direction.x;
	pt.y = ray.originpt.y + dist * ray.direction.y;
	pt.z = ray.originpt.z + dist * ray.direction.z;
	return (pt);
}

t_vector			distvect(t_vector pt1, t_vector pt2)
{
	t_vector	vector;

	vector.x = pt1.x - pt2.x;
	vector.y = pt1.y - pt2.y;
	vector.z = pt1.z - pt2.z;
	return (vector);
}

t_vector			crossproduct(t_vector a, t_vector b)
{
	t_vector result;
	
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_vector			changelenght(t_vector vector, float module)
{
	float		moduleoriginal;
	float		factor;

	moduleoriginal = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	factor = moduleoriginal / module;
	vector.x /= factor;
	vector.y /= factor;
	vector.z /= factor;
	return (vector);
}