/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:36:05 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/26 14:20:39 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;

	len = 0;
	slen = ft_strlen(src);
	while (*dest && size > 0)
	{
		dest++;
		len++;
		size--;
	}
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
	}
	if (size == 1 || *src == 0)
		*dest = '\0';
	return (slen + len);
}
