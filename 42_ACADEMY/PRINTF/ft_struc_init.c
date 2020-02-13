/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struc_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:42:00 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/13 21:37:44 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_struc_init(t_var *count)
{
	count->i = 0;
	count->j = 1;
	count->chcount = 0;
	count->flag0 = 0;
	count->flagm = 0;
	count->flagp = 0;
	count->flags = 0;
	count->nflags = 0;
	count->flag_is_negative = 0;
	count->nbr = 0;
	count->nbrm = 0;
	count->nbr0 = 0;
	count->nbrp = 0;
	count->large = 0;
	count->tam = 0;
	count->tam_p = 0;
	count->n = 0;
	count->p = 0;
	count->u = 0;
	count->hex_str = 0;
}