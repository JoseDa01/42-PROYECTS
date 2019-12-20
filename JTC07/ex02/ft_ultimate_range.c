/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:28:38 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/23 17:26:39 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int *tab;
    int i;
    int contador;

    tab = malloc(sizeof(*tab));
    i = 0;
    if (min > max)
    {
        return (0);
    }
    while (tab[min] != tab [max])
    {
        tab[i] = tab[min]
        i++;
    }

	contador = 0;
	while (tab[range] != '\0')
	{
		range++;
	}
    return (range);
}