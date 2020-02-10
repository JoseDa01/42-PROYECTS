/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:17:15 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/10 20:48:57 by jtello-m         ###   ########.fr       */
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
		if (count->flagm == 1)
			ft_flag_minus(count);
	}
	else
	{
		write(1, "(null)", 6);
		count->chcount += 6;
		count->s = NULL;
		if (count->flagm == 1)
			ft_flag_minus(count);
	}
}

void	ft_prec_str(t_var *count)
{
	int i;
	char *n;

	n = "(null)";
	i = 0;
	if (count->s != NULL)
	{
		while (i <= count->nbr - 1) 
		{
			write(1, &count->s[i], 1);
			i++;
			count->chcount++;
		}
		if (count->flagm == 1)
			ft_flag_minus(count);
	}
	else
	{
		//loop hasta el prec
		while (i <= count->nbr - 1)
		{
			write(1, &n[i], 1);
			i++;
		}
		count->chcount += (count->nbr - 1);
		count->s = NULL;
		if (count->flagm == 1)
			ft_flag_minus(count);
	}
}

void	ft_args_str(const char *str, t_var *count, va_list fa)
{
	count->s = (char *)va_arg(fa, void *);
	count->tam = strlen(count->s);
	ft_app_flags(str, count);
	if (count->flagp == 1 && (count->tam >= count->nbr))
		ft_prec_str(count);
	else if (count->flagp == 0 || count->tam <= count->nbr)
		ft_str(count);
}