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

void	ft_hex(char *str, t_var *count)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
			ft_flag_minus(count);
}


void	ft_args_hex(const char *str, t_var *count, va_list fa)
{
	count->hex = va_arg(fa, unsigned long);
	if (str[count->i] == 'x')
		count->hex_str = ft_itoa_base(count->hex, 16, "0123456789abcdef");
	if (str[count->i] == 'X')
		count->hex_str = ft_itoa_base(count->hex, 16, "0123456789ABCDEF");
	count->tam = strlen(count->hex_str);
	if (count->flagp == 1 && count->tam >= count->nbrp)
		count->tam = count->nbrp;
	if (count->flagm == 1 && count->tam >= count->nbrm)
		count->tam = count->nbrm;
	ft_app_flags(str, count);
	ft_int(count->hex_str, count);
}