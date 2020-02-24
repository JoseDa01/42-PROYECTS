/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:22:48 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/21 18:58:36 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen1((char *)s1);
	lens2 = ft_strlen1((char *)s2);
	str = malloc(lens1 + lens2 + 1);
	if (str)
	{
		ft_memcpy(str, s1, lens1);
		ft_memcpy(str + lens1, s2, lens2 + 1);
	}
    free((char *)s1);
    free((char *)s2);
	return (str);
}
