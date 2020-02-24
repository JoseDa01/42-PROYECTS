/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:36:03 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/23 01:45:11 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_writeflags(int nbr, int tam, int j, t_var *count)
{
	while (j <= nbr - tam)
	{
		write(1, "0", 1);
		j++;
		count->chcount++;
	}
}

void	ft_writeflags_int(int tam, int j, t_var *count)
{
	if (count->flag_is_negative == 1)
		write(1, "-", 1);
	while (j <= count->nbrp - tam)
	{
		write(1, "0", 1);
		j++;
		count->chcount++;
	}
}

void	ft_writeflags_str(int i, char *str, t_var *count)
{
	while (i <= count->nbrp - 1)
	{
		write(1, &str[i], 1);
		count->chcount++;
		i++;
	}
}

void	starflag_auxnbr0(t_var *count)
{
	if (count->nbr0 < 0)
	{
		count->nbr0 *= (-1);
		count->nbrm = count->nbr0;
		count->nbr0 = 0;
		count->flagm = 1;
		count->flag0 = 0;
	}
}
