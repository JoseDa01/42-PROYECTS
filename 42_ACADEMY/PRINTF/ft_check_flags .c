/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:15:21 by jtello-m          #+#    #+#             */
/*   Updated: 2020/01/30 17:47:31 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_flags(const char *str, t_var *count)
{
	if (str[count->i] == '-')
		count->flagm = 1;
	else if (str[count->i] == '0')
		count->flag0 = 1;
	else if (str[count->i] == '.')
		count->flagp = 1;
	else if (str[count->i] == '*')
		count->flags = 1;
	else if (str[count->i] >= '0' && str[count->i] <= '9')
	{
		count->nflags = 1;
		count->nbr = ft_atoi(str + 1, count);
		if (!(count->large == 1))
			count->i += count->large;
	}
	else
		return (0);
	return (1);
}