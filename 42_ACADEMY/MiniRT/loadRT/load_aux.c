/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:31:41 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 19:47:44 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load.h"

void	error(char *s)
{
	write(2, "error\n", 6);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}

void	freespace(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	countwords(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
		i++;
	return (i);
}

void	addobject(t_scene *scene, void *object)
{
	static t_list_obj	*list;

	if (list == NULL)
		scene->objets = object;
	else
		list->next = object;
	list = object;
}
