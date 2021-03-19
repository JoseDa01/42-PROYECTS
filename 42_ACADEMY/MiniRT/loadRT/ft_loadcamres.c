/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadcamres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:53:25 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 19:25:39 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

void	loadresol(t_scene *scene, char **comp)
{	
	if (compcounter(comp) != 3)
		printf("ERROR\nformato de resolucion no valido\n");
	scene->resolution.x = ft_atoi(comp[1]);
	scene->resolution.y = ft_atoi(comp[2]);
}

void	init_camera(t_camera *cam, t_resol resol)
{
	cam->vectorx = perpendicular_rand_vect(cam->direction);
	cam->vectory = crossproduct(cam->vectorx, cam->direction);
	cam->vectorx = changelenght(cam->vectorx, 1);
	cam->vectory = changelenght(cam->vectory, 1);
	cam->direction = changelenght(cam->direction, 1);
	cam->fov_rad = (cam->fov / 360) * 2 * M_PI;
	cam->depth = resol.x / (2 * tan(cam->fov_rad / 2));
}

void	loadcam(t_scene *scene, char **comp)
{
	t_camera *cam;

	if (compcounter(comp) != 4)
		printf("ERROR\nformato de camara no valido\n");
	cam = ft_calloc(1, sizeof(t_camera));
	cam->origin_point = loadpoint(comp[1]);
	cam->direction = loadvector(comp[2]);
	cam->fov = atoi(comp[3]);
	init_camera(cam, scene->resolution);
}