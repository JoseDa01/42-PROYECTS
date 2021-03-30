/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:33:20 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:18 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	size_t		n;

	if (dst == NULL || src == NULL)
		return ((size_t)((src == NULL) ? src : dst));
	s = src;
	n = dstsize;
	if (n != 0)
		while (--n != 0)
			if ((*dst++ = *src++) == '\0')
				break ;
	if (n == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return ((size_t)(src - s - 1));
}
