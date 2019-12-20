/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:53:40 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/09 20:38:45 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		rev_tab[size];

	i = 0;
	while (i < size)
	{
		rev_tab[size - i - 1] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = rev_tab[i];
		i++;
	}
}
