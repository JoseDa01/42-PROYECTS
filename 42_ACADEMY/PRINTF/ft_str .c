/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:17:15 by jtello-m          #+#    #+#             */
/*   Updated: 2020/01/30 17:19:24 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_str(t_var *count)
{
	int i;
	
	i = 0;
	if (count->s != NULL)
	{
		while (count->s[i] != '\0')
		{
			write(1, &count->s[i], 1);
			i++;
			count->chcount++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		count->chcount += 6;
		count->s = NULL;
	}
	
}

void	ft_args_str(const char *str, t_var *count, va_list fa)
{
	count->s = (char *)va_arg(fa, void *);
	count->tam = strlen(count->s);
	ft_app_flags(str, count);
	ft_str(count);
	//funcion de las ramas;
}