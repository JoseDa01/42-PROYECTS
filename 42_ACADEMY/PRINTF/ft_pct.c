/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:41:24 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/20 21:12:54 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pct(t_var *count)
{
	write(1, "%", 1);
	count->chcount++;
	if (count->flagm == 1)
		ft_flag_minus(count);
}

void	ft_args_pct(const char *str, t_var *count)
{
	count->tam = 1;
	ft_app_flags(str, count);
	ft_pct(count);
}
