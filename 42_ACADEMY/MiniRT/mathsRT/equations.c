/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:46:47 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 19:46:40 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_tupla	solveequation(t_tupla equation, double equal)
{
	t_tupla	solution;

	ft_bzero(&solution, sizeof(t_tupla));
	if (equation.tam == 3)
		solution = solveequation2(equation, equal);
	else if (equation.tam == 2)
		solution = solveequation1(equation, equal);
	return (solution);
}

t_tupla	solveequation2(t_tupla equation, double equal)
{
	t_tupla		solution;
	double		insideroot;
	double		outsideroot;
	double		root;

	equation.tupla[2] -= equal;
	insideroot = pow(equation.tupla[1], 2) - 4
		* equation.tupla[0] * equation.tupla[2];
	root = sqrt(insideroot);
	outsideroot = -(equation.tupla[1]);
	if (insideroot < 0)
		solution.tam = 0;
	else if (insideroot == 0)
	{
		solution.tam = 1;
		solution.tupla[0] = (outsideroot + root) / (2 * equation.tupla[0]);
	}
	else
	{
		solution.tam = 2;
		solution.tupla[0] = (outsideroot + root) / (2 * equation.tupla[0]);
		solution.tupla[1] = (outsideroot - root) / (2 * equation.tupla[0]);
	}
	return (solution);
}

t_tupla	solveequation1(t_tupla equation, double equal)
{
	t_tupla	solution;

	if (equation.tupla[0] == 0)
		solution.tam = 0;
	else
	{
		solution.tam = 1;
		solution.tupla[0] = (equal - equation.tupla[1]) / equation.tupla[0];
	}
	return (solution);
}
