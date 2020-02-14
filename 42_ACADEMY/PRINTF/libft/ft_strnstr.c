/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:07:42 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/06 15:59:19 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	int		find;
	int		i;
	int		j;
	char	*ptr;

	ptr = NULL;
	find = 0;
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		find = 1;
	while (str[i] != '\0' && find == 0 && len > 0)
	{
		if (str[i] == needle[j])
			j++;
		else
			j = 0;
		if (needle[j] == '\0')
			find = 1;
		i++;
		len--;
	}
	if (find == 1)
		ptr = (char *)str + i - j;
	return (ptr);
}
