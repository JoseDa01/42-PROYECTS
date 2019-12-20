/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:26:29 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/26 22:26:31 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char				*ft_strcpy(char *dest, char *src)
{
	int	contador;

	contador = 0;
	while (src[contador] != '\0')
	{
		dest[contador] = src[contador];
		contador++;
	}
	dest[contador] = src[contador];
	return (dest);
}

int					ft_strlen(char *str)
{
	int contador;

	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	return (contador);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*ptr;
	int				i;

	ptr = malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		ptr[i].size = ft_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = malloc(ptr[i].size + 1);
		ft_strcpy(ptr[i].copy, ptr[i].str);
		i++;
	}
	ptr[i].str = 0;
	return (ptr);
}
