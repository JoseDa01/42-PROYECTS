/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:27:28 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/23 17:22:13 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int *ft_range(int min, int max)
{
    int *tab;
    int i;

    tab = malloc(sizeof(*tab);)
    i = 0;
    if (min > max)
    {
        return (NULL);
    }
    while (tab[min] != tab [max])
    {
        tab[i] = tab[min]
        i++;
    }
    return (tab;)
}