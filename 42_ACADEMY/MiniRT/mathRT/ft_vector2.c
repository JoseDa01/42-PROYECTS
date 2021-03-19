/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 02:20:23 by marvin            #+#    #+#             */
/*   Updated: 2021/03/15 02:20:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

float		distancept(t_vector point1, t_vector point2)
{
	float	dist;

	dist = 0;
	dist += pow(point1.x - point2.x, 2);
	dist += pow(point1.y - point2.y, 2);
	dist += pow(point1.z - point2.z, 2);
	dist = sqrt(dist);
	return (dist);

}

t_vector		perpendicular_rand_vect(t_vector vector)
{
	t_tupla		equation;
	t_tupla		solution;
	t_vector	new_vector;

	equation.tamaño = 2;
	new_vector.x = 1;
	new_vector.y = 1;
	new_vector.z = 1;
	if (vector.x != 0)
	{
		equation.tupla[1] = vector.y + vector.z;
		equation.tupla[0] = vector.x;
		solution = solvequation(equation, 0);
		new_vector.x = solution.tupla[0];
	}
	else if (vector.y != 0)
	{
		equation.tupla[1] = vector.x + vector.z;
		equation.tupla[0] = vector.y;
		solution = solvequation(equation, 0);
		new_vector.y = solution.tupla[0];
	}
	else
	{
		equation.tupla[1] = vector.x + vector.y;
		equation.tupla[0] = vector.z;
		solution = solvequation(equation, 0);
		new_vector.z = solution.tupla[0];
	}
	return (new_vector);
}

float			modulevector(t_vector vector)
{
	float		module;

	module = 0;
	module += pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2);
	module = sqrt(module);
	return (module); 
}

float			angle2vects(t_vector vector1, t_vector vector2)
{
	float		sclproduct;
	float		cos;

	sclproduct = vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	cos = sclproduct / (modulevector(vector1) * modulevector(vector2));
	return (cos);
}
