/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:18:22 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/06 12:48:23 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;

	i = 0;
	while (dest[i] != '\0')
		i++;
	res = 0;
	while (src[res] != '\0')
		++res;
	if (size <= i)
		res += size;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}
