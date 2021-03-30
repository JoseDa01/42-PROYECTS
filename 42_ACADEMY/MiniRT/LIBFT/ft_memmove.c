/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:34:16 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:04 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*f;
	char		*t;

	f = src;
	t = dst;
	if ((f != NULL || t != NULL) && len != 0)
	{
		if (f < t)
		{
			f += len;
			t += len;
			while (len-- > 0)
				*(--t) = *(--f);
		}
		else
			while (len-- > 0)
				*t++ = *f++;
	}
	return (dst);
}
