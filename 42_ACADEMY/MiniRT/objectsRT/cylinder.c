/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:21:03 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 20:19:15 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_intersection	*cylindercollision(t_rayo ray, t_cylinder *cyl)
{
	t_intersection	**intersection;
	t_intersection	*returned;

	intersection = ft_calloc(3, sizeof(t_intersection *));
	ini_tops(cyl);
	intersection[0] = cylindercollisiontransformed(ray, *cyl);
	intersection[1] = circlecollision(ray, &(cyl->upper_top));
	intersection[2] = circlecollision(ray, &(cyl->lower_top));
	returned = returnnear(intersection[0], intersection[1]);
	returned = returnnear(returned, intersection[2]);
	free(intersection);
	if (returned == NULL)
		return (NULL);
	returned->object = cyl;
	returned->color = cyl->color;
	return (returned);
}

t_cylinder	*inicylinder(t_cylinder *cyl)
{
	cyl->vect1 = perpendicular_rand_vect(cyl->normal);
	cyl->vect2 = crossproduct(cyl->vect1, cyl->normal);
	cyl->normal = changelenght(cyl->normal, 1);
	cyl->vect1 = changelenght(cyl->vect1, 1);
	cyl->vect2 = changelenght(cyl->vect2, 1);
	cyl->base = inimatrix(cyl->normal, cyl->vect1, cyl->vect2);
	cyl->inversebase = inversematrix(cyl->base);
	return (cyl);
}

t_intersection	*cylindercollisiontransformed(t_rayo ray, t_cylinder cyl)
{
	t_tupla			productos[3];
	t_intersection	*intersection;
	t_tupla			solution;
	t_vect3			point;
	double			menor;

	rotatecollision(&ray, &cyl);
	productos[0] = notableproduct(ray.vector.y, ray.punto.y - cyl.point.y);
	productos[1] = notableproduct(ray.vector.z, ray.punto.z - cyl.point.z);
	productos[2] = addtupla(productos[0], productos[1]);
	solution = solveequation(productos[2], pow(cyl.diameter / 2, 2));
	if (solution.tam <= 0)
		return (NULL);
	menor = lowernumber(solution);
	point = pointray(ray, menor);
	if (pow(point.x - cyl.point.x, 2) > pow(cyl.height / 2, 2))
		return (NULL);
	intersection = ft_calloc(1, sizeof(t_intersection));
	intersection->lambda = menor;
	intersection->color = cyl.color;
	intersection->normal = calcnormalcyl(cyl, point, cyl.base);
	return (intersection);
}
