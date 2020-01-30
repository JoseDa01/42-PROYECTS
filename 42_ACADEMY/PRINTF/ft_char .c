/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:09:00 by jtello-m          #+#    #+#             */
/*   Updated: 2020/01/24 19:06:13 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_char(t_var *count)
{
	write(1, &count->a, 1);
	count->chcount++;
}

void    ft_args_c(t_var *count, va_list fa)
{
	count->a = (char)va_arg(fa, void *);
	ft_char(count);
	//funcion de las ramas;
}