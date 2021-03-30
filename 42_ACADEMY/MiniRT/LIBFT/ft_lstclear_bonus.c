/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:50:00 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:37:51 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *aux;
	t_list *lst1;

	lst1 = *lst;
	if (*lst || lst)
	{
		while (lst1->next != NULL)
		{
			aux = lst1->next;
			del(lst1->content);
			free(lst1);
			lst1 = aux;
		}
		del(lst1->content);
		free(lst1);
		*lst = NULL;
	}
}
