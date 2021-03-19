/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:17:03 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 13:36:44 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

t_tupla			solvequation(t_tupla equation, float nb)
{
	t_tupla		solution;
	
	ft_bzero(&solution, sizeof(t_tupla));
	if (equation.tamaño == 3)
		solution = solvequation2(equation, nb);
	else if (equation.tamaño == 2)
		solution = solvequation1(equation, nb);
	return (solution);
}

t_tupla			solvequation1(t_tupla equation, float nb)
{
	t_tupla		solution;

	if (equation.tupla[0] == 0)
		solution.tamaño = 0;
	else
	{
		solution.tamaño = 1;
		solution.tupla[0] = (nb - equation.tupla[1]) / equation.tupla[0];
	}
	return (solution);
}

t_tupla			solvequation2(t_tupla equation, float nb)
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