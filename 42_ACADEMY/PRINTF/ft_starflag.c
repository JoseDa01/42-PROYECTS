/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:13:33 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/23 06:06:03 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_starflag(const char *str, t_var *count, va_list fa)
{
	if (str[count->i - 1] == '-')
	{
		count->nbrm = (int)va_arg(fa, void *);
		if (count->nbrm < 0)
			count->nbrm *= (-1);
	}
	else if (str[count->i - 1] == '0')
	{
		count->nbr0 = (int)va_arg(fa, void *);
		starflag_auxnbr0(count);
	}
	else if (str[count->i - 1] == '.')
		starpt(str, count, fa);
	else
	{
		count->nbr = (int)va_arg(fa, void *);
		count->nflags = 1;
		starflag_auxnbr(count);
	}
}

void	starflag_auxnbr(t_var *count)
{
	if (count->nbr < 0)
	{
		count->nbr *= (-1);
		count->nbrm = count->nbr;
		count->nbr = 0;
		count->flagm = 1;
		count->nflags = 0;
	}
}

void	starpt(const char *str, t_var *count, va_list fa)
{
	int flagstr;
	int i;

	i = 0;
	flagstr = 0;
	count->nbrp = (int)va_arg(fa, void *);
	while (str[i] != '\0')
	{
		if (str[i] == 's')
			flagstr = 1;
		i++;
	}
	if (flagstr == 1)
	{
		if (count->nbrp < 0)
		{
			count->nbrp *= (-1);
			if (count->nbrm <= count->nbrp)
				count->nbrm = count->nbrp;
			count->nbrp = 0;
			count->flagm = 1;
			count->flagp = 0;
		}
	}
}
