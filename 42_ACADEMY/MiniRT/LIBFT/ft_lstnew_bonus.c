/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:38:33 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:38:00 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content)
{
	t_list *ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr != NULL)
	{
		ptr->content = (void *)content;
		ptr->next = NULL;
	}
	return (ptr);
}
