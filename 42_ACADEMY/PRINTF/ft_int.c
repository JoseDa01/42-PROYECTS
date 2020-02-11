/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:00:35 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/11 21:27:44 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_int(char *str_int, t_var *count)
{
	int i;

	i = 0;
	while (str_int[i] != '\0')
	{
		write(1, &str_int[i], 1);
		i++;
		count->chcount++;
	}
}

void	ft_args_int(const char *str, t_var *count, va_list fa)
{
	(void)str;
	count->n = (int)va_arg(fa, void *);
	ft_int(ft_itoa(count->n), count);
}