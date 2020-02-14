/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:32:28 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/18 17:14:09 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (lst == NULL)
		return (NULL);
	if ((new_lst = ft_lstnew(lst->content)) == NULL)
		return (NULL);
	new_lst->content = (*f)(new_lst->content);
	new_lst->next = ft_lstmap(lst->next, f, del);
	return (new_lst);
}
