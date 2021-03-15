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

solvequation2(t_tupla equation, float nb)
{
	t_tupla		solution;
	float		insideroot;
	float		outsideroot;
	float		root;

	equation.tupla[2] -= nb;
	insideroot = pow(equation.tupla[1], 2) - 4 * equation.tupla[0] * equation.tupla[2];
	root = sqrt(insideroot);
	outsideroot = -(equation.tupla[1]);
	if (insideroot < 0)
		solution.tamaño = 0;
	else if (insideroot == 0)
	{
		solution.tamaño = 1;
		solution.tupla[0] = (outsideroot + root) / (2 * equation.tupla[0]);
	}
	else
	{
		solution.tamaño = 2;
		solution.tupla[0] = (outsideroot + root) / (2 * equation.tupla[0]);
		solution.tupla[1] = (outsideroot - root) / (2 * equation.tupla[0]);
	}
	return (solution);
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
		solution = solveequation(equation, 0);
		new_vector.x = solution.tupla[0];
	}
	else if (vector.y != 0)
	{
		equation.tupla[1] = vector.x + vector.z;
		equation.tupla[0] = vector.y;
		solution = solveequation(equation, 0);
		new_vector.y = solution.tupla[0];
	}
	else
	{
		equation.tupla[1] = vector.x + vector.y;
		equation.tupla[0] = vector.z;
		solution = solveequation(equation, 0);
		new_vector.z = solution.tupla[0];
	}
	return (new_vector);
}
