/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:08:25 by marvin            #+#    #+#             */
/*   Updated: 2020/02/12 02:08:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hex(const char *hex_str, t_var *count)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (count->flagp == 1 && count->nbrp > count->tam)
	{
		while (j <= count->nbrp - count->tam)
		{
			write(1, "0", 1);
			j++;
			count->chcount++;
		}
	}
	else if (count->flagp == 1 && count->nbrp == count->tam)
	{
		while (j <= count->nbrp - count->tam_p)
		{
			write(1, "0", 1);
			j++;
			count->chcount++;
		}
	}
	while (hex_str[i] != '\0')
	{
		if (count->flagp == 1 && count->nbrp == 0)
			break;
		write(1, &hex_str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
		ft_flag_minus(count);
}


void	ft_args_hex(const char *str, t_var *count, va_list fa)
{
	if (count->flag0 == 1 && count->flagp == 1)
	{
		count->nflags = 1;
		count->nbr = count->nbr0;
		count->flag0 = 0;
	}
	count->hex = va_arg(fa, unsigned long);
	if (str[count->i] == 'x')
		count->hex_str = ft_itoa_base(count->hex, 16, "0123456789abcdef");
	if (str[count->i] == 'X')
		count->hex_str = ft_itoa_base(count->hex, 16, "0123456789ABCDEF");
	count->tam = ft_strlen1(count->hex_str);
	count->tam_p = count->tam;
	if (count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	if (count->flag0 == 1 && count->flag_is_negative == 1)
		count->tam += 1;
	if (count->nflags == 1 && count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	if (count->flagp == 1 && count->nbrp == 0)
		count->tam = 0;
	ft_app_flags(str, count);
	ft_hex(count->hex_str, count);
}