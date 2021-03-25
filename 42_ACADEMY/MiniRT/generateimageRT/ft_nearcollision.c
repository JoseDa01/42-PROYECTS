/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearcollision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:33:05 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:44:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "generateimagert.h"

t_intersection		*returnnear(t_intersection *first, t_intersection *second)
{
	t_intersection *returned;

	first = infront(first);
	second = infront(second);
	if (first != NULL && second != NULL)
	{
		if (first->lambda > second->lambda)
			returned = second;
		else
			returned = first;
	}
	if (first == NULL)
		returned = second;
	else if (second == NULL)
		returned = first;
	if (returned != first && first != NULL)
		free(first);
	if (returned != second && second != NULL)
		free(second);
	return (returned);
}

t_intersection		*infront(t_intersection *intersection)
{
	if (intersection == NULL)
		return (NULL);
	if (intersection->lambda <= 0)
	{
		free(intersection);
		return (NULL);
	}
	return (intersection);
}