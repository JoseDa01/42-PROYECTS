/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:49:04 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/17 17:57:18 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersectionsrt.h"

t_intersection				*spherecollision(t_ray ray, t_sphere *esfera)
{
	t_tupla				x;
	t_tupla				y;
	t_tupla				z;
	t_tupla				equation;
	t_intersection		*spherecoll;

	x = notableproduct(ray.direction.x, ray.originpt.x - esfera->point.x);
	y = notableproduct(ray.direction.y, ray.originpt.y - esfera->point.y);
	z = notableproduct(ray.direction.z, ray.originpt.z - esfera->point.z);
	equation = addtupla(x, y);
	equation = addtupla(equation, z);
	equation = solvequation(equation, pow(esfera->radio, 2));
	if (equation.tamaño <= 0)
		return (NULL);
	spherecoll = ft_calloc(1, sizeof(t_intersection));
	spherecoll->object = esfera;
	spherecoll->color = esfera->color;
	spherecoll->dist = lowernb(equation);
	spherecoll->normalvect = distvect(pointray(ray, spherecoll->dist), esfera->point);
	return (spherecoll);
}