/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:15:31 by jtello-m          #+#    #+#             */
/*   Updated: 2020/01/30 18:14:30 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_app_flags(const char *str, t_var *count)
{
	(void)str;
	if (count->nflags == 1)
	{
		while (count->j <= (count->nbr - count->tam))
		{
			//tener en cuenta el str[i];
			count->j++;
			write(1, " ", 1);
			count->chcount++;
		}	
	}
}