/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:22:13 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 18:37:24 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generateimagert.h"

t_rgbcolor			secondaryray(t_scene *scene, t_ray raycam, t_intersection *intersection)
{
	t_list_lights		*lights;
	t_intersection		*objectlight;
	float				d[2];
	t_rgbcolor			color;
	t_ray				ray;

	lights = scene->lights;
	ft_bzero(&color, sizeof(t_rgbcolor));
	while (lights != NULL)
	{
		objectlight = NULL;
		ray = raytolight(intersection, raycam, lights->light);
		d[0] = distancept(ray.originpt, lights->light.light_point);
		objectlight = raycollision(scene->objects, ray);
		if (objectlight != NULL)
			d[1] = distancept(pointray(ray, objectlight->dist), ray.originpt);
		if (d[0] < d[1] || objectlight == NULL)
			color = addcolor(calcolor(intersection, ray, lights->light.luminosity, lights->light.color), color);
		lights = lights->next;
		if (objectlight != NULL)
			free(objectlight);
	}
	return (color);
}

t_intersection		*primaryray(t_scene *scene, t_ray *ray, int pixelx, int pixely)
{
	t_intersection		*intersection;

	*ray = cordtoray(pixelx, pixely, scene);
	intersection = raycollision(scene->objects, *ray);
	if (intersection != NULL && intersection->dist <= 0)
	{
		free(intersection);
		intersection = NULL;
	}
	return(intersection);
}

void				writepixelimg(t_libx *libx, t_rgbcolor color, int x, int y)
{
	libx->img_addr = (int *)mlx_get_data_addr(libx->img, &libx->img_data.bits_per_pixel, &libx->img_data.length, &libx->img_data.end);
	libx->img_addr[(libx->img_data.length / 4) * y + x] = colortoint(color);
	mlx_pixel_put(libx->mlx, libx->mlx_win, x, y, colortoint(color));
}

void				raytracing(t_scene scene, t_libx *libx)
{
	int						i;
	int						j;
	t_intersection			*intersection;	
	t_ray					ray;
	t_all_colors			colors;

	libx->img = mlx_new_image(libx->mlx, scene.resolution.x, scene.resolution.y);
	ft_bzero(&colors, sizeof(t_all_colors));
	i = 0;
	j = 0;
	while (i < scene.resolution.y)
	{
		while(j < scene.resolution.x)
		{
			intersection = primaryray(&scene, &ray, j, i);
			if (intersection != NULL)
			{
				colors.color_lights = secondaryray(&scene, ray, intersection);
				colors.color_am = ambienlight(&scene, intersection);
				writepixelimg(libx, fusion_colors(colors), j, i);
			}
			if (intersection == NULL)
				free(intersection);
			j++;
		}
		i++;
		j = 0;
	}
}