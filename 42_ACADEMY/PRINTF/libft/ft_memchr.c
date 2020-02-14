/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:03:45 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/06 16:21:43 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*a;
	char			*ptr;

	a = (char *)s;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		if (a[i] == ((char)c))
			ptr = a + i;
		i++;
	}
	return (ptr);
}
