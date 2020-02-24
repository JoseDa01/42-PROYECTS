/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:48:59 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/20 21:13:28 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

char	*ft_itoa_u(unsigned int n)
{
	char *str_int;

	if (!(str_int = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n < 0)
	{
		str_int[0] = '-';
		str_int[1] = '\0';
		str_int = ft_strjoin(str_int, ft_itoa(-n));
	}
	else if (n >= 10)
		str_int = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str_int[0] = n + '0';
		str_int[1] = '\0';
	}
	return (str_int);
}
