/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:17:37 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/13 17:59:23 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_ptr(t_var *count)
{
	int i;

	i = 0;
	write(1, "0x", 2);
	count->chcount += 2;
	while (count->p_str[i] != '\0')
	{
		write(1, &count->p_str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
		ft_flag_minus(count);
	//hacer un itoa, para coger el valor de la dirrecion de memoria que esta en hex
}

void	ft_args_ptr(const char *str, t_var *count, va_list fa)
{
	(void)str;
	count->p = (int)va_arg(fa, void *);
	count->p_str = ft_itoa_base(count->p, 16, "0123456789abcdef");
	count->tam = strlen(count->p_str) + 2;
	ft_app_flags(str, count);
	ft_ptr(count);
}