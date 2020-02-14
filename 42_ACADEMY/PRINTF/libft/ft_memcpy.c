/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:41:01 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/13 21:20:05 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = dst;
	b = (void*)src;
	if (!n || dst == src)
		return (dst);
	while (n-- > 0)
	{
		*a++ = *b++;
	}
	return (dst);
}
