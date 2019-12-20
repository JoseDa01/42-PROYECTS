/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:04 by jtello-m          #+#    #+#             */
/*   Updated: 2019/12/20 18:45:55 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_var count;

	count.i = 0;
	while(str[count.i] != '\0')
	{
		if (str[count.i] == '%')
		{
			write(1, "H", 1);
			return(0);
		}
		else
		{
			write(1, &str[count.i], 1);	
		}
		count.i++;
	}
	return (0);
}
