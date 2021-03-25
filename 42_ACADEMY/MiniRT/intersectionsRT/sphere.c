/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:49:04 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:54:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersectionsrt.h"

t_intersection			*spherecollision(t_rayo rayo, t_esfera *esfera)
{
	t_tupla			productox;
	t_tupla			productoy;
	t_tupla			productoz;
	t_tupla			equation;
	t_intersection	*returned;

	productox = notableproduct(rayo.vector.x, rayo.punto.x - esfera->punto.x);
	productoy = notableproduct(rayo.vector.y, rayo.punto.y - esfera->punto.y);
	productoz = notableproduct(rayo.vector.z, rayo.punto.z - esfera->punto.z);
	equation = addtupla(productox, productoy);
	equation = addtupla(equation, productoz);
	equation = solveequation(equation, pow(esfera->radio, 2));
	if (equation.tamaño <= 0)
		return (NULL);
	returned = ft_calloc(1, sizeof(t_intersection));
	returned->object = esfera;
	returned->color = esfera->color;
	returned->lambda = lowernumber(equation);
	returned->normal = distancevector(pointray(rayo, returned->lambda), esfera->punto);
	return (returned);
}
