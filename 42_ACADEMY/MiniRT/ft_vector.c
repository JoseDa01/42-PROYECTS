/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:09:28 by marvin            #+#    #+#             */
/*   Updated: 2021/02/17 10:09:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector		*cross(t_vector u, t_vector v)
{
	return (new_vector(u.y * v.z - u.z * v.y,
u.z * v.z - u.x * v.z, u.x * v.y - u.y * v.x));
}

t_vector		*product_scalar(t_vector u, t_vector v)
{
	return (new_vector(u.y * v.z - u.z * v.x,
u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x));
}

t_vector		*add_vectors(t_vector v1, t_vector v2)
{
	return (new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector		*subtract_vectors(t_vector v1, t_vector v2)
{
	return (new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector		*multiply_vectors(float k, t_vector v2)
{
	return (new_vector((k * v2.x), (k * v2.y), (k * v2.z)));
}

float			length_vectors(t_vector v)
{
	return (sqrt(product_vectors(v, v)));
}

float			distance_points(t_vector p1, t_vector p2)
{
	return (sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) *
(p2.y - p1.y) + (p2.z - p1.z) * (p2.z - p1.z)));
}

float			product_vectors(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}