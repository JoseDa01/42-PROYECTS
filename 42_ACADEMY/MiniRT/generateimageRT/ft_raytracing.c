/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:22:13 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:43:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generateimagert.h"

t_color			secondaryray(t_scene *scene, t_rayo raycam, t_intersection *intersectionobject)
{
	t_list_light	*light;
	t_intersection	*lightobstacle;
	double			distance[2];
	t_color			color;
	t_rayo			ray;

	light = scene->lights;
	ft_bzero(&color, sizeof(t_color));
	while (light != NULL)
	{
		lightobstacle = NULL;
		ray = raytolight(intersectionobject, raycam, light->point);
		distance[0] = distancepoint(ray.punto, light->point.point);
		lightobstacle = raycollision(scene->objets, ray);
		if (lightobstacle != NULL)
			distance[1] = distancepoint(pointray(ray, lightobstacle->lambda), ray.punto);
		if (distance[0] < distance[1] || lightobstacle == NULL)
			color = addcolor(calccolor(intersectionobject, ray, light->point.intensity, light->point.color), color);
		light = light->next;
		if (lightobstacle != NULL)
			free(lightobstacle);
	}
	return (color);
}

t_intersection	*primaryray(t_scene *scene, t_rayo *ray, int pixelx, int pixelj)
{
	t_intersection *intersection;

	*ray = cordtoray(pixelx, pixelj, scene);
	intersection = raycollision(scene->objets, *ray);
	if (intersection != NULL && intersection->lambda <= 0)
	{
		free(intersection);
		intersection = NULL;
	}
	return (intersection);
}

void			writepixelimage(t_libx *libx, t_color color, int x, int y)
{
	int bitpixel;
	int size_line;
	int endian;

	libx->img_addr = (int *)mlx_get_data_addr(libx->img_ptr, &bitpixel, &size_line, &endian);
	libx->img_addr[(size_line / 4) * y + x] = colortoint(color);
	mlx_pixel_put(libx->ptr, libx->win_ptr, x, y, colortoint(color));
}

void			generateimage(t_scene scene, t_libx *libx)
{
	int					i;
	int					j;
	t_intersection		*intersection;
	t_colors_reflected	colors;
	t_rayo				ray;

	libx->img_ptr = mlx_new_image(libx->ptr, scene.resolution.x, scene.resolution.y);
	ft_bzero(&colors, sizeof(t_colors_reflected));
	i = 0;
	j = 0;
	while (i < scene.resolution.y)
	{
		while (j < scene.resolution.x)
		{
			intersection = primaryray(&scene, &ray, j, i);
			if (intersection != NULL)
			{
				colors.color_lights = secondaryray(&scene, ray, intersection);
				colors.color_ambient = ambientlight(&scene, intersection);
				writepixelimage(libx, fusion_colors(colors), j, i);
			}
			if (intersection != NULL)
				free(intersection);
			j++;
		}
		i++;
		j = 0;
	}
}