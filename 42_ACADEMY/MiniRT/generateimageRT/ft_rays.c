/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:32:33 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:43:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generateimagert.h"

t_rayo			cordtoray(int i, int j, t_scene *scene)
{
	t_rayo		ray;
	t_vect3		vectx;
	t_vect3		vecty;
	t_vect3		vectz;

	ray.punto = scene->camera->origin;
	vectz = mulvector(scene->camera->direction, scene->camera->depth);
	vectx = mulvector(scene->camera->vectorx, i - scene->resolution.x / 2);
	vecty = mulvector(scene->camera->vectory, scene->resolution.y / 2 - j);
	ray.vector = addvector(vectx, vecty);
	ray.vector = addvector(ray.vector, vectz);
	return (ray);
}

t_intersection	*raycollision(t_list_obj *objects, t_rayo ray)
{
	t_intersection	*(*collision)(t_rayo, void *);
	t_intersection	*morenear;
	t_intersection	*actualintersection;
	t_list_obj		*actualobject;

	actualobject = objects;
	morenear = NULL;
	while (actualobject != NULL)
	{
		collision = actualobject->functioncoll;
		actualintersection = (*collision)(ray, actualobject->object);
		morenear = returnnear(morenear, actualintersection);
		actualobject = actualobject->next;
	}
	return (morenear);
}

t_rayo			raytolight(t_intersection *intersection, t_rayo primary, t_light_point light)
{
	t_rayo		secondary;
	t_vect3		originpoint;

	originpoint = pointray(primary, intersection->lambda - 0.000001);
	secondary.punto = originpoint;
	secondary.vector = distancevector(light.point, originpoint);
	return (secondary);
}
