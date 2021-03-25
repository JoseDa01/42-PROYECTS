/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadcamres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:53:25 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:33:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

void			loadresolution(t_scene *scene, char **words)
{
	static int countcalls = 0;

	countcalls++;
	if (countcalls > 1)
		error("solo debe de haber una resolucion");
	if (countwords(words) != 3)
		error("mal formato de resolucion");
	scene->resolution.x = ft_atoi(words[1]);
	scene->resolution.y = ft_atoi(words[2]);
	fundamentalsobjects("resolution");
}

void			loadcamera(t_scene *scene, char **words)
{
	static int			countcalls = 0;
	static t_camera		*camera_list = NULL;

	countcalls++;
	if (countwords(words) != 4)
		error("mal formato de camara");
	if (camera_list == NULL)
	{
		camera_list = ft_calloc(1, sizeof(t_camera));
		scene->camera = camera_list;
	}
	else
	{
		camera_list->next = ft_calloc(1, sizeof(t_camera));
		camera_list->next->back = camera_list;
		camera_list = camera_list->next;
	}
	camera_list->origin = chargepoint(words[1]);
	camera_list->direction = chargenormalizedvector(words[2]);
	camera_list->fov_h = ft_atoi_double(words[3]);
	inicamera(camera_list, scene->resolution);
	fundamentalsobjects("camera");
}

int				fundamentalsobjects(char *str)
{
	static int camera = 0;
	static int resolution = 0;

	if (ft_strncmp(str, "camera", ft_strlen(str)))
		camera = 1;
	else if (ft_strncmp(str, "resolution", ft_strlen(str)))
		resolution = 1;
	return (camera & resolution);
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
