/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:31:52 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 19:51:42 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load.h"

void	loadambientlight(t_scene *scene, char **words)
{
	static int	countcalls = 0;

	countcalls++;
	if (countcalls > 1)
		error("solo debe de haber una luz ambiental");
	if (countwords(words) != 3)
		error("mal formato de luz ambiental");
	scene->env_light.intensity = ft_atoi_double(words[1]);
	scene->env_light.color = chargecolor(words[2]);
}

void	loadlight(t_scene *scene, char **words)
{
	static t_list_light	*light_list;

	if (countwords(words) != 4)
		error("mal formato de luz");
	if (light_list == NULL)
	{
		light_list = ft_calloc(1, sizeof(t_list_light));
		scene->lights = light_list;
	}
	else
	{
		light_list->next = ft_calloc(1, sizeof(t_list_light));
		light_list = light_list->next;
	}
	light_list->point.point = chargepoint(words[1]);
	light_list->point.intensity = ft_atoi_double(words[2]);
	light_list->point.color = chargecolor(words[3]);
}
