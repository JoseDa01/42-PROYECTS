/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:15:31 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/13 21:55:50 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_app_flags(const char *str, t_var *count)
{
	(void)str;
	if (count->flag0 == 1 && count->flagp == 0)
	{
		while (count->j <= (count->nbr0 - count->tam))
		{
			count->j++;
			write(1, "0", 1);
			count->chcount++;
		}
	}
	if (count->nflags == 1)
	{
		while (count->j <= (count->nbr - count->tam))
		{
			count->j++;
			write(1, " ", 1);
			count->chcount++;
		}
	}
}

void	ft_flag_minus(t_var *count)
{
	count->j = 1;
	
	while (count->j <= (count->nbrm - count->tam))
	{
		count->j++;
		write(1, " ", 1);
		count->chcount++;
	}
}