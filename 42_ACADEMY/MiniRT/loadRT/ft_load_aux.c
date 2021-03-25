/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:02:43 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 13:35:59 by jtello-m         ###   ########.fr       */
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


double			ft_atoi_double(char *number)
{
	int			i;
	double		after_point;
	double 		returned;
	int			sign;

	i = 0;
	after_point = 0;
	returned = 0;
	sign = 1;
	if(number[0] == '-')
		sign = -1;
	while(number[i] != '\0')
	{
		if(number[i] == '.')
			after_point = 10;
		else if(number[i] >= '0' && number[i] <= '9')
		{
			if(after_point == 0)
				returned = returned * 10 + number[i] - '0';
			else
			{
				returned += (number[i] - '0') / after_point;
				after_point *= 10;
			}
		}
		i++;
	}
	return (sign * returned);
}