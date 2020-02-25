/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:01:54 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/25 17:10:25 by jtello-m         ###   ########.fr       */
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
		ft_writeflags(count->nbrp, count->tam, j, count);
	else if (count->flagp == 1 && count->nbrp == count->tam)
		ft_writeflags(count->nbrp, count->tam_p, j, count);
	while (u_str[i] != '\0')
	{
		if (count->flagp == 1 && count->nbrp == 0)
			break ;
		write(1, &u_str[i], 1);
		i++;
		count->chcount++;
	}
	if (count->flagm == 1)
		ft_flag_minus(count);
}

void	ft_args_u(const char *str, t_var *count, va_list fa)
{
	if (count->flag0 == 1 && count->flagp == 1)
	{
		count->nflags = 1;
		count->nbr = count->nbr0;
		count->flag0 = 0;
	}
	count->u = (unsigned int)va_arg(fa, void *);
	count->u_str = ft_itoa_u(count->u);
	count->tam = ft_strlen1(count->u_str);
	count->tam_p = count->tam;
	if (count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	if (count->flag0 == 1 && count->flag_is_negative == 1)
		count->tam += 1;
	if (count->nflags == 1 && count->flagp == 1 && count->tam <= count->nbrp)
		count->tam = count->nbrp;
	if (count->flagp == 1 && count->nbrp == 0)
		count->tam = 0;
	ft_app_flags(str, count);
	ft_u(count->u_str, count);
	free(count->u_str);
}
