/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:59:05 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:37:50 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *aux;

	aux = *alst;
	if (aux == NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		new->next = NULL;
	}
}
