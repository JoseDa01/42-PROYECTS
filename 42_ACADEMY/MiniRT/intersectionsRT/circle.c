/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 03:00:28 by marvin            #+#    #+#             */
/*   Updated: 2021/03/25 03:00:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersectionsrt.h"

t_intersection		*circlecollision(t_rayo ray, t_circle *cir)
{
	double			lambda;
	double			distance;
	t_vect3			intersection_point;
	t_intersection	*returned;

	lambda = pseudointersection(ray, cir->center, cir->normal);
	if (lambda < 0)
		return (NULL);
	intersection_point = pointray(ray, lambda);
	distance = distancepoint(cir->center, intersection_point);
	if (distance > cir->radius)
		return (NULL);
	returned = ft_calloc(1, sizeof(t_intersection));
	returned->lambda = lambda;
	returned->object = cir;
	returned->color = cir->color;
	returned->normal = cir->normal;
	return (returned);
}