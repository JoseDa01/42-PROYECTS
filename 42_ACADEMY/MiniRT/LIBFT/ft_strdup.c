/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:37 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:10 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*aux;
	int		i1;
	int		i2;

	i1 = 0;
	while (str1[i1] != '\0')
		i1++;
	aux = malloc(i1 + 1);
	if (aux == NULL)
		return (NULL);
	i2 = 0;
	while (i2 < i1)
	{
		aux[i2] = str1[i2];
		i2++;
	}
	aux[i1] = '\0';
	return (aux);
}
