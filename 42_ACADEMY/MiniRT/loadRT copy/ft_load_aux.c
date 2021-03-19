/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:02:43 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 19:24:58 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

int		compcounter(char **comp)
{
	int i;

	i = 0;
	while (comp[i] != NULL)
		i++;
	return(i);
}

void	freecomps(char **comp)
{
	int i;

	i = 0;
	while(comp[i] != NULL)
	{
		free(comp[i]);
		i++;
	}
	free(comp);
}

void			addobject(t_scene *scene, void *object)
{
	static t_list_objects *list;

	if (list == NULL)
		scene->objects = object;
	else
		list->next = object;
	list = object;
}

float	ft_atof(char *str)
{
	int i;
	float number;
	float flag;
	int sign;

	i = 0;
	number = 0;
	flag = 0;
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			flag = 10;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (flag == 0)
				number = number * 10 + str[i] - '0';
			else
			{
				number += (str[i] - '0') / flag;
				flag *= 10;
			}
		}
		i++;
	}
	return(sign * number);
}