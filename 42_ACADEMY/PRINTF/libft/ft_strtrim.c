/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:10:57 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/18 20:09:34 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*trimed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	len = ft_strlen(&s1[start]);
	if (len != 0)
	{
		while (s1[start + len - 1]
			&& ft_strchr(set, s1[start + len - 1]) != NULL)
			len--;
	}
	if ((trimed = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	trimed = strncpy(trimed, &s1[start], len);
	trimed[len] = '\0';
	return (trimed);
}
