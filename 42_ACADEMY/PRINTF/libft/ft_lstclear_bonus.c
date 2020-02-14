/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:32:03 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/18 13:46:23 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_ptr;

	while (*lst)
	{
		lst_ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = lst_ptr;
	}
}
