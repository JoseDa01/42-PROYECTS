/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:20:49 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/12 12:29:04 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t	total;
	void	*p;

	total = n * size;
	p = malloc(total);
	if (!p)
	{
		return (NULL);
	}
	return (memset(p, 0, total));
}
