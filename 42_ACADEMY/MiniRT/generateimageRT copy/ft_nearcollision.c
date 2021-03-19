/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearcollision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:33:05 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 14:09:07 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "generateimagert.h"

t_intersection			*returnnear(t_intersection *first, t_intersection *second)
{
	t_intersection		*nearcoll;

	first = behindcam(first);
	second = behindcam(second);
	if (first != NULL && second != NULL)
	{
		if (first->dist > second->dist)
			nearcoll = second;
		else
			nearcoll = first;
	}
	if (first == NULL)
		nearcoll = second;
	if (second == NULL)
		nearcoll = first;
	if (nearcoll != first && first != NULL)
		free(first);
	if (nearcoll != second && second != NULL)
		free(second);
	return (nearcoll);
}

t_intersection			*behindcam(t_intersection *intersection)
{
	if (intersection == NULL)
		return (NULL);
	if (intersection->dist <= 0)
	{
		free(intersection);
		return (NULL);
	}
	return (intersection);
}