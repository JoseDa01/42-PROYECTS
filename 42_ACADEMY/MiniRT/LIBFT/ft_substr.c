/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:22:56 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:23 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	unsigned int	i;
	size_t			size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	aux = malloc(len + 1);
	if (aux == NULL)
		return (NULL);
	if (start < size)
	{
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			aux[i] = s[start + i];
			i++;
		}
		aux[i] = '\0';
	}
	else
		return (ft_strdup(""));
	return (aux);
}
