/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:59:02 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/14 22:00:22 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_insert_string(char **table, char *str)
{
	int		i;
	char	**aux;

	i = 0;
	while (table[i] != NULL)
		i++;
	i = i + 2;
	aux = malloc(i * sizeof(char *));
	i = 0;
	while (table[i] != NULL)
	{
		aux[i] = table[i];
		i++;
	}
	aux[i] = str;
	aux[i + 1] = NULL;
	free(table);
	return (aux);
}
