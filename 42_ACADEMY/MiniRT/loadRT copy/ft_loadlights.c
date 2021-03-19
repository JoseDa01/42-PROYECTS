/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadlights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:00:40 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 18:50:00 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

void		loadamlight(t_scene *scene, char **comp)
{
	if (compcounter(comp) != 3)
		printf("ERROR\nformato de luz ambiental no valido\n");
	scene->am_light.luminosity = ft_atof(comp[1]);
	scene->am_light.color = loadcolor(comp[2]);
}

void		loadlight(t_scene *scene, char **comp)
{
	static t_list_lights	*light_list;

	if (compcounter(comp) != 4)
		printf("ERROR\nformato de foco de luz no valido\n");
	if (light_list == NULL)
	{
		light_list = ft_calloc(1, sizeof(t_list_lights));
		scene->lights = light_list;
	}
	else
	{
		light_list->next = ft_calloc(1, sizeof(t_list_lights));
		light_list = light_list->next;
	}
	light_list->light.light_point = loadpoint(comp[1]);
	light_list->light.luminosity = ft_atof(comp[2]);
	light_list->light.color = loadcolor(comp[3]);
}