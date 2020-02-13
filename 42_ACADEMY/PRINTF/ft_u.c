/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:01:54 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/13 17:56:48 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_u(const char *u_str, t_var *count)
{
	int i;

	i = 0;
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
	(void)str;
	count->u = (unsigned int)va_arg(fa, void *);
	count->u_str = ft_itoa_u(count->u);
	count->tam = strlen(count->u_str);
	ft_app_flags(str, count);
	ft_u(count->u_str, count);
}