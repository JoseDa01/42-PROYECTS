/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:56:04 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/18 16:24:16 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t n)
{
	char	*res;
	int		i;
	int		l;

	l = 0;
	if (str == NULL)
		return (NULL);
	while (str[l])
		l++;
	res = malloc((n + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (l < (int)start)
		return (ft_strdup(""));
	i = 0;
	while (i < (int)n && str[i] != 0)
	{
		res[i] = str[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}
