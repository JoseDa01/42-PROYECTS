/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:33:49 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:02 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *p;

	if (n != 0)
	{
		p = s;
		while (n-- != 0)
		{
			if (*p++ == (char)c)
				return ((void *)(p - 1));
		}
	}
	return (NULL);
}
