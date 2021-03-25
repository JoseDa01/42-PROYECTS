/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changecam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 02:41:02 by marvin            #+#    #+#             */
/*   Updated: 2021/03/25 02:41:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "generateimagert.h"

int			changecamera(t_scene *scene, int next)
{
	int		change;

	change = 0;
	if (next == 1)
	{
		if (scene->camera->next != NULL)
		{
			change = 1;
			write(1, "PROCESANDO...", 14);
			scene->camera = scene->camera->next;
		}
		else
			write(1, "HA LLEGADO A LA ULTIMA CAMARA, NO QUEDAN MAS CAMARAS\n", 54);
	}
	else
	{
		if (scene->camera->back != NULL)
		{
			change = 1;
			write(1, "PROCESANDO...", 14);
			scene->camera = scene->camera->back;
		}
		else
			write(1, "ESTAN EN LA PRIMERA CAMARA, AVANCE SI QUIERE CAMBIAR DE CAMARA\n", 64);
	}
	return (change);
}
