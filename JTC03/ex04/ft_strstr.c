/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:17:44 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/06 12:26:10 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		find;
	int		i;
	int		j;
	char	*ptr;

	ptr = NULL;
	find = 0;
	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		find = 1;
	while (str[i] != '\0' && find == 0)
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		if (to_find[j] == '\0')
			find = 1;
		i++;
	}
	if (find == 1)
		ptr = str + i - j;
	return (ptr);
}