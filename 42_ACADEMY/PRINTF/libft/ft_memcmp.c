/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:18:15 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/13 21:28:37 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;
	char unsigned	*a;
	char unsigned	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}
