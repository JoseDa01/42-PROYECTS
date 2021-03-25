/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:02:43 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:32:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

void			error(char *s)
{
	write(2, "error\n", 6);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}

void			freespace(char **words)
{
	int i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int				countwords(char **words)
{
	int i;

	i = 0;
	while (words[i] != NULL)
		i++;
	return (i);
}

void			addobject(t_scene *scene, void *object)
{
	static t_list_obj *list;

	if (list == NULL)
		scene->objets = object;
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