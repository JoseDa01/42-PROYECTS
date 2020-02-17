/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:13:33 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/17 21:01:29 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_starflag(const char *str, t_var *count, va_list fa)
{
	if (str[count->i - 1] == '-')
		count->nbrm = (int)va_arg(fa, void *);
	else if (str[count->i - 1] == '0')
		count->nbr0 = (int)va_arg(fa, void *);
		if (count->nbr0 < 0)
		{
			count->nbr0 *= (-1);
			count->nbrm = count->nbr0;
			count->nbr0 = 0;
			count->flagm = 1;
			count->flag0 = 0;
		}
	else if (str[count->i - 1] == '.')
		count->nbrp = (int)va_arg(fa, void *);
		//IDEA : HACER UN BUCLE Q ENCUENTRE S O (D, I , U)
		//PARA ASI HACER UNA COSA U OTRA .
	else
	{
		count->nbr = (int)va_arg(fa, void *);
		count->nflags = 1;
		if (count->nbr < 0)
		{
			count->nbr *= (-1);
			count->nbrm = count->nbr;
			count->nbr = 0;
			count->flagm = 1;
			count->nflags = 0;
		}
	}
}