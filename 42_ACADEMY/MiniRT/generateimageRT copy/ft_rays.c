/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:32:33 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 19:32:40 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generateimagert.h"

t_ray				cordtoray(int pixelx, int pixely, t_scene *scene)
{
	t_ray		ray;
	t_vector	vectorx;
	t_vector	vectory;
	t_vector	vectorz;
	
	ray.originpt = scene->camera->origin_point;
	vectorz = multvect(scene->camera->direction, scene->camera->depth);
	vectorx = multvect(scene->camera->vectorx, pixelx - scene->resolution.x / 2);
	vectory = multvect(scene->camera->vectory, scene->resolution.y / 2 - pixely);
	ray.direction = addvect(vectorx, vectory);
	ray.direction = addvect(ray.direction, vectorz);
	return(ray);
}

t_intersection		*raycollision(t_list_objects *object, t_ray ray)
{
	t_intersection		*(*collision)(t_ray, void *);
	t_intersection		*morenear;
	t_intersection		*actualintersection;
	t_list_objects		*actualobject;

	actualobject = object;
	morenear = NULL;
	while(actualobject != NULL)
	{
		collision = actualobject->functioncoll;
		actualintersection = (*collision)(ray, actualobject->object);
		morenear = returnnear(morenear, actualintersection);
		actualobject = actualobject->next;
	}
	return(morenear);
}

t_ray			raytolight(t_intersection *intersection, t_ray primary, t_light light)
{
	t_ray		second;
	t_vector	originpoint;

	originpoint = pointray(primary, intersection->dist - 0.000001);
	second.originpt = originpoint;
	second.direction = distvect(light.light_point, originpoint);
	return (second);
}
