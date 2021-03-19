/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadobjects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:45:12 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 17:37:10 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

void		loadsphere(t_scene *scene, char **comp)
{
	t_sphere			*sp;
	t_list_objects		*list;

	if (compcounter(comp) != 4)
		printf("ERROR\nformato de esfera no valido\n");
	list = ft_calloc(1, sizeof(t_list_objects));
	list->type = sphere;
	sp = ft_calloc(1, sizeof(t_sphere));
	sp->point = loadpoint(comp[1]);
	sp->radio = atof(comp[2]) / 2;
	sp->color = loadcolor(comp[3]);
	list->object = sp;
	list->functioncoll = &spherecollision;
	addobject(scene, list);
}