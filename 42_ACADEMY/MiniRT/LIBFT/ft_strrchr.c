/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:28:36 by eligero           #+#    #+#             */
/*   Updated: 2021/03/30 18:38:22 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *t;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	t = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			t = (char *)s;
		s++;
	}
	return (t);
}
