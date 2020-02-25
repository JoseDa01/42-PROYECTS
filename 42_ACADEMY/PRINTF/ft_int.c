/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:00:35 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/25 17:45:03 by jtello-m         ###   ########.fr       */
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
		ft_writeflags_int(count->tam, j, count);
	else if (count->flagp == 1 && count->nbrp == count->tam)
		ft_writeflags_int(count->tam_p, j, count);
	if (count->flag_is_negative == 1 &&
	count->flagp == 1 && count->tam > count->nbrp)
		write(1, "-", 1);
	while (n_str[i] != '\0')
	{
		if (count->flagp == 1 && count->nbrp == 0)
			break ;
		write(1, &n_str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
		ft_flag_minus(count);
}

void	ft_args_int(const char *str, t_var *count, va_list fa)
{
	if (count->flag0 == 1 && count->flagp == 1)
	{
		count->nflags = 1;
		count->nbr = count->nbr0;
		count->flag0 = 0;
	}
	count->n = va_arg(fa, int);
	if (count->n < 0 && (count->flag0 == 1 || count->flagp == 1))
	{
		count->flag_is_negative = 1;
		count->n *= (-1);
		count->chcount++;
	}
	count->n_str = ft_itoa(count->n);
	count->tam = ft_strlen1(count->n_str);
	count->tam_p = count->tam;
	special_cases(count);
	ft_app_flags(str, count);
	ft_int(count->n_str, count);
	free(count->n_str);
}

void	special_cases(t_var *count)
{
	if (count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	if (count->flag0 == 1 && count->flag_is_negative == 1)
		count->tam += 1;
	if (count->nflags == 1 && count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	if (count->flag_is_negative == 1)
	{
		count->nbr -= 1;
		count->nbrm -= 1;
	}
	if (count->flagp == 1 && count->nbrp == 0)
		count->tam = 0;
}
