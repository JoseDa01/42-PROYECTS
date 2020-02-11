/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struc_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:07:44 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/11 17:43:56 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_struc_reset(t_var *count)
{
    count->flag0 = 0;
	count->flagm = 0;
	count->flagp = 0; 
	count->flags = 0;
	count->nflags = 0;
	count->nbr = 0;
	count->nbrm = 0;
	count->nbr0 = 0;
	count->nbrp = 0;
	count->large = 0;
	count->tam = 0;
	count->j = 1;
}