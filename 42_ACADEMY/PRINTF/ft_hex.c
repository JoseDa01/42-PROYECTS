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

void	ft_hex(t_var *count)
{
	int i;

	i = 0;
	while (count->hex_str != '\0')
	{
		write(1, &hex_str[i], 1);
		i++;
		count->chcount++;
	}
}


void	ft_args_hex(t_var *count)
{
	count->hex = va_arg(fa, unsigned long);
	count->hex_str = ft_itoa_base(count->hex, 16);
	count->tam = ft_strlen(count->hex_str);
	ft_hex(t_var *count);
}