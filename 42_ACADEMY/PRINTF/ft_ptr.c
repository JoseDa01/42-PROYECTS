/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:17:37 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/10 16:26:54 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_ptr(t_var *count)
{
	count->p = "hola";
	//hacer un itoa, para coger el valor de la dirrecion de memoria que esta en hex
}

void	ft_args_ptr(const char *str, t_var *count, va_list fa)
{
	count->p = (char *)va_arg(fa, void *);
	count->tam = strlen(count->s);
	ft_app_flags(str, count);
	ft_str(count);
}