/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:48:59 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/25 20:46:28 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

static void	recursive(int length, char cad[], unsigned int num, int neg)
{
	if (length > neg)
		recursive(length - 1, cad, num / 10, neg);
	cad[length] = (num % 10) + '0';
}

static int	ft_intlen(unsigned int n)
{
	unsigned int n1;
	unsigned int num;

	num = 0;
	n1 = n;
	if (n1 < 0)
		n1 *= -1;
	if (n1 && ft_isdigit((n1 % 10) + '0'))
	{
		num = ft_intlen((n1 / 10));
		return (1 + num);
	}
	return (0);
}

char		*ft_itoa_u(unsigned int n)
{
	char	*num;
	int		use[3];

	use[0] = 0;
	use[1] = 0;
	num = NULL;
	if (n <= 0)
	{
		n *= -1;
		use[0] = 1;
	}
	use[2] = ft_intlen(n);
	if ((num = (char*)malloc((use[2] + use[0]) * sizeof(char) + 1)) && use[0])
		*(num + use[1]++) = '-';
	if (!num)
		return (NULL);
	if (!use[0])
		recursive(use[2] - 1, num, n, use[0]);
	else
		recursive(use[2], num, n, use[0]);
	num[use[2] + use[0]] = '\0';
	return (num);
}
