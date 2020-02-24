/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:17:37 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/21 18:54:54 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_ptr(const char *p_str, t_var *count)
{
	int i;
	int j;

	i = 0;
	j = 1;
	write(1, "0x", 2);
	count->chcount += 2;
	if (count->flagp == 1 && count->nbrp >= count->tam)
		ft_writeflags(count->nbrp, count->tam_p, j, count);
	while (p_str[i] != '\0')
	{
		write(1, &p_str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
	{
		count->tam += 2;
		ft_flag_minus(count);
	}
}

void	ft_args_ptr(const char *str, t_var *count, va_list fa)
{
	int flagpt;

	flagpt = 0;
	count->p = (unsigned long)va_arg(fa, void *);
	count->p_str = ft_itoa_base(count->p, 16, "0123456789abcdef");
	if (count->nbrp == 0 && count->flagp == 1)
		count->tam = ft_strlen1(count->p_str) + 1;
	else if (count->nflags == 1 && count->flagp == 0)
		count->tam = ft_strlen1(count->p_str) + 2;
	else
		count->tam = ft_strlen1(count->p_str);
	count->tam_p = count->tam;
	if (count->tam >= count->nbrp && count->flagp == 1)
		count->tam_p = count->nbrp;
	if (count->flagp == 1 && count->nbrp == 0)
	{
		count->p_str = "";
		flagpt = 1;
	}
	if (count->flagp == 1 && count->nflags == 1 && flagpt == 0)
		count->tam += 2;
	ft_app_flags(str, count);
	ft_ptr(count->p_str, count);
}
