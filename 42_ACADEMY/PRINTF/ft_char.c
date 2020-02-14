/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:09:00 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/14 21:26:32 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_char(t_var *count)
{
	write(1, &count->a, 1);
	count->chcount++;
	if (count->flagm == 1)
		ft_flag_minus(count);
}

void    ft_args_c(char const *str, t_var *count, va_list fa)
{
	count->a = (char)va_arg(fa, void *);
	count->tam = ft_strlen1(&count->a);
	if (!(count->a))
		count->tam += 1;
	ft_app_flags(str, count);
	ft_char(count);
}