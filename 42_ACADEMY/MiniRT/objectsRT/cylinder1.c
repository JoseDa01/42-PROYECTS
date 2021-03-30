/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:18:47 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/29 20:19:11 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	rotatecollision(t_rayo *ray, t_cylinder *cyl)
{
	ray->punto = rotatevector(cyl->inversebase, ray->punto);
	ray->vector = rotatevector(cyl->inversebase, ray->vector);
	cyl->point = rotatevector(cyl->inversebase, cyl->point);
	cyl->normal = rotatevector(cyl->inversebase, cyl->normal);
	cyl->vect1 = rotatevector(cyl->inversebase, cyl->vect1);
	cyl->vect2 = rotatevector(cyl->inversebase, cyl->vect2);
}

void	ini_tops(t_cylinder *cyl)
{
	cyl->upper_top.center = pointvectorpoint(cyl->point,
			cyl->normal, cyl->height / 2);
	cyl->lower_top.center = pointvectorpoint(cyl->point,
			cyl->normal, -cyl->height / 2);
	cyl->lower_top.normal = mulvector(cyl->normal, -1);
	cyl->upper_top.normal = cyl->normal;
	cyl->upper_top.radius = cyl->diameter / 2;
	cyl->lower_top.radius = cyl->diameter / 2;
	cyl->lower_top.color = cyl->color;
	cyl->upper_top.color = cyl->color;
}

t_vect3	calcnormalcyl(t_cylinder cyl, t_vect3 interspt, t_matrix3 matrix)
{
	t_vect3	inpoint;
	t_vect3	normal;

	inpoint = cyl.point;
	inpoint.x = interspt.x;
	normal = distancevector(interspt, inpoint);
	normal = rotatevector(matrix, normal);
	return (normal);
}
