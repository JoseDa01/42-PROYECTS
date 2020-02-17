/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:17:37 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/17 20:09:23 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_ptr(const char *p_str, t_var *count)
{
	int i;

	i = 0;
	write(1, "0x", 2);
	count->chcount += 2;
	if (count->flagp == 0)
	{
		while (p_str[i] != '\0')
		{
			write(1, &p_str[i], 1);
			i++;
			count->chcount++;
		}
		if (count->flagm == 1)
			ft_flag_minus(count);
	}
	else if (count->flagp == 1)
	{
		while (i <= count->nbrp - 1)
		{
			write(1, &p_str[i], 1);
			i++;
			count->chcount++;
		}
		if (count->flagm == 1)
			ft_flag_minus(count);
	}
}

void	ft_args_ptr(const char *str, t_var *count, va_list fa)
{
	count->p = (int)va_arg(fa, void *);
	count->p_str = ft_itoa_base(count->p, 16, "0123456789abcdef");
	if (count->nbrp == 0 && count->flagp == 1)
		count->tam = ft_strlen1(count->p_str) + 1;
	else
		count->tam = ft_strlen1(count->p_str) + 2;	
	ft_app_flags(str, count);
	ft_ptr(count->p_str, count);
}