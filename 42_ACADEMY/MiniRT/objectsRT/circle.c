/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:46:01 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 19:39:56 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_intersection	*circlecollision(t_rayo ray, t_circle *cir)
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
