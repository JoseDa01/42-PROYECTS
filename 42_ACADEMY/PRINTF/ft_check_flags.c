/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:15:21 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/13 14:11:50 by jtello-m         ###   ########.fr       */
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
	else if (str[count->i] > '0' && str[count->i] <= '9')
		assig_nbr(str, count);
	else
		return (0);
	return (1);
}

void	assig_nbr(const char *str, t_var *count)
{
	if (str[count->i - 1] == '-'|| str[count->i - 2] == '-')
	{
		count->nbrm = ft_atoi(str + count->i, count);
		//if (count->large == 0 || count->large == 1)
		count->i += (count->large - 1);
		if (count->nbrm < 0)
		{
			count->nbrm = (count->nbrm * (-1));
			count->i++;
		}
	}
	else if (str[count->i - 1] == '0' && count->flagm == 0 && count->flagp == 0)
	{
		count->nbr0 = ft_atoi(str + count->i, count);
		//if (count->large == 0 || count->large == 1)
		count->i += (count->large - 1);
		if (count->nbr0 < 0)
		{
			count->nbr0 = (count->nbr0 * (-1));
			count->i++;
		}
	}
	else if (str[count->i - 1] == '.' || str[count->i - 2] == '.')
	{
		count->nbrp = ft_atoi(str + count->i, count);
		//if (count->large == 0 || count->large == 1)
		count->i += (count->large - 1);
		if (count->nbrp < 0)
		{
			count->nbrp = (count->nbrp * (-1));
			count->i++;
		}
	}
	else
	{
		count->nflags = 1;
		count->nbr = ft_atoi(str + count->i, count);
		//if (count->large == 0 || count->large == 1)
		count->i += (count->large - 1);
		if (count->nbr < 0)
		{
			count->nbr = (count->nbr * (-1));
			count->i++;
		}
	}
}