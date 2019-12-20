/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:28:51 by jtello-m          #+#    #+#             */
/*   Updated: 2019/12/12 20:43:09 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_newstr(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ret = malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	k = 0;
	while (k != i)
	{
		ret[k] = s1[k];
		k++;
	}
	while (k != j + i)
	{
		ret[k] = s2[k - i];
		k++;
	}
	ret[k] = '\0';
	free(s1);
	return (ret);
}

char		*ft_strdup(char *src)
{
	char	*n;
	int		i;
	int		tam;

	tam = 0;
	while (src[tam])
		++tam;
	n = (char*)malloc(sizeof(*n) * tam + 1);
	if (n == NULL)
		return (NULL);
	i = 0;
	while (i < tam)
	{
		n[i] = src[i];
		i++;
	}
	n[tam] = '\0';
	return (n);
}

char		*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (str == NULL)
		return (NULL);
	ret = ft_newstr(len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[start + i];
		i++;
	}
	return (ret);
}

void		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
