/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:49:51 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/13 22:29:12 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*cp_dst;
	unsigned const char		*cp_src;

	cp_dst = dst;
	cp_src = src;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			cp_dst[len] = cp_src[len];
	return (dst);
}
