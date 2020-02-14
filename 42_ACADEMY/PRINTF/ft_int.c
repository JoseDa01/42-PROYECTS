/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:00:35 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/14 21:35:16 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_int(char *n_str, t_var *count)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (count->flagp == 1 && count->nbrp > count->tam)
	{
		if (count->flag_is_negative == 1)
			write(1, "-", 1);
		while (j <= count->nbrp - count->tam)
		{
			write(1, "0", 1);
			j++;
			count->chcount++;
		}
	}
	else if (count->flagp == 1 && count->nbrp == count->tam)
	{
		if (count->flag_is_negative == 1)
			write(1, "-", 1);
		while (j <= count->nbrp - count->tam_p)
		{
			write(1, "0", 1);
			j++;
			count->chcount++;
		}
	}
	while (n_str[i] != '\0')
	{
		if (count->flagp == 1 && count->nbrp == 0)
			break;
		write(1, &n_str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
		ft_flag_minus(count);
}

void	ft_args_int(const char *str, t_var *count, va_list fa)
{
	count->n = (int)va_arg(fa, void *);
	if (count->n < 0 && (count->flag0 == 1 || count->flagp == 1))
	{
		count->flag_is_negative = 1;
		count->n *= (-1);
		count->chcount++;
	}
	count->n_str = ft_itoa(count->n);
	count->tam = ft_strlen1(count->n_str);
	count->tam_p = count->tam;
	if (count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	if (count->flagm == 1 && count->tam >= count->nbrm)
		count->tam = count->nbrm;
	if (count->flag0 == 1 && count->flag_is_negative == 1)
		count->tam += 1;
	if (count->nflags == 1 && count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	ft_app_flags(str, count);
	ft_int(count->n_str, count);
}