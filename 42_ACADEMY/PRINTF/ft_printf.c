/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:04 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/14 19:59:50 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list	fa;
	t_var	*count;
	
	if (!(count = (t_var *)malloc(sizeof(t_var))))
		return (-1);
	count->i = 0;
	va_start(fa, str);
	ft_struc_init(count);
	while(str[count->i] != '\0')
	{
		if (str[count->i] == '%')
		{
			count->i++;
			ft_flags(str, count, fa);
			ft_struc_reset(count);
		}
		else
		{
			write(1, &str[count->i], 1);
			count->chcount++;	
		}
		count->i++;
	}
	va_end(fa);
	return (count->chcount);
}

void	ft_flags(const char *str, t_var *count, va_list fa)
{
	while (ft_check_flags(str, count))
	{
		count->i++;
	}
	ft_format(str, count, fa);
}

void	ft_format(const char *str, t_var *count, va_list fa)
{
	if (str[count->i] == 's')
		ft_args_str(str, count, fa);
	else if (str[count->i] == 'c')
		ft_args_c(str, count, fa);
	else if (str[count->i] == 'p')
		ft_args_ptr(str, count, fa);
	else if (str[count->i] == 'd' || str[count->i] == 'i')
		ft_args_int(str, count, fa);
	else if (str[count->i] == 'x' || str[count->i] == 'X')
		ft_args_hex(str, count, fa);
	else if (str[count->i] == '%')
		ft_args_pct(str, count);
	else if (str[count->i] == 'u')
		ft_args_u(str, count, fa);
}
