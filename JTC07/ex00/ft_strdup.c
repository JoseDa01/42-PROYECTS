/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:26:03 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/08 05:47:21 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
​
char	*ft_strdup(char *src)
{
	char	*n;
	int		i;
	int		tam;
​
	tam = 0;
	while (src[tam])
		++tam;
	if (!(n = malloc(sizeof(char) * (tam + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		n[i] = src[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
