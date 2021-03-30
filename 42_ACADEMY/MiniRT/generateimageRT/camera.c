/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:01:38 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 19:08:40 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generateimage.h"

void	inicamera(t_camera *camera, t_resolution resolution)
{
	camera->vectorx = perpendicular_rand_vect(camera->direction);
	camera->vectory = crossproduct(camera->vectorx, camera->direction);
	camera->vectorx = changelenght(camera->vectorx, 1);
	camera->vectory = changelenght(camera->vectory, 1);
	camera->direction = changelenght(camera->direction, 1);
	camera->fov_h_rad = (camera->fov_h / 360) * 2 * M_PI;
	camera->depth = resolution.x / (2 * tan(camera->fov_h_rad / 2));
}

int	changecamera(t_scene *scene, int next)
{
	int		change;

	change = 0;
	if (next == 1)
	{
		if (scene->camera->next != NULL)
		{
			change = 1;
			scene->camera = scene->camera->next;
			printf("CARGANDO...\n");
		}
	}
	else
	{
		if (scene->camera->back != NULL)
		{
			change = 1;
			scene->camera = scene->camera->back;
			printf("CARGANDO...\n");
		}
	}
	return (change);
}
