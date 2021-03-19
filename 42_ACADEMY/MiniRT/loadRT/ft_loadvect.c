/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadvect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:26:56 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 19:10:55 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

t_vector		loadpoint(char *point)
{
	t_vector	lpoint;
	char		**comp;
	
	comp = ft_split(point, ',');
	if (compcounter(comp) != 3)
	{
		printf("ERROR\nlos datos recibidos no son validos (punto)\n");
		exit(-1);
	}
	lpoint.x = ft_atof(comp[0]);
	lpoint.y = ft_atof(comp[1]);
	lpoint.z = ft_atof(comp[2]);
	freecomps(comp);
	
	return(lpoint);
}

t_rgbcolor		loadcolor(char *color)
{
	t_rgbcolor	rgb;
	char		**comp;

	comp = ft_split(color, ',');
	if (compcounter(comp) != 3)
		printf("ERROR\nlos datos recibidos no son validos (color)\n");
	rgb.red = ft_atoi(comp[0]);
	rgb.green = ft_atoi(comp[1]);
	rgb.blue = ft_atoi(comp[2]);
	freecomps(comp);

	return(rgb);
}

t_vector		loadvector(char *vector)
{
	t_vector	lvector;
	char		**comp;

	comp = ft_split(vector, ',');
	if (compcounter(comp) != 3)
		printf("ERROR\nlos datos recibidos no son validos (vector)\n");
	lvector.x = ft_atof(comp[0]);
	lvector.y = ft_atof(comp[1]);
	lvector.z = ft_atof(comp[2]);
	freecomps(comp);

	return(lvector);
}