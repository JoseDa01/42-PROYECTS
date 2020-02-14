/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:01:54 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/14 21:34:11 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_u(const char *u_str, t_var *count)
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
	while (u_str[i] != '\0')
	{
		write(1, &u_str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
		ft_flag_minus(count);
}

void	ft_args_u(const char *str, t_var *count, va_list fa)
{
	count->u = (unsigned int)va_arg(fa, void *);
	count->u_str = ft_itoa_u(count->u);
	count->tam = ft_strlen1(count->u_str);
	ft_app_flags(str, count);
	ft_u(count->u_str, count);
}