/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:05:32 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/25 21:09:52 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void	recursive(int length, char cad[], int num, int neg)
{
	if (length > neg)
		recursive(length - 1, cad, num / 10, neg);
	cad[length] = (num % 10) + '0';
}

static int	ft_intlen(int n)
{
	int n1;
	int num;
	num = 0;
	n1 = (long)n;
	if (n1 < 0)
		n1 *= -1;
	if (n1 && ft_isdigit((n1 % 10) + '0'))
	{
		num = ft_intlen((n1 / 10));
		return (1 + num);
	}
	return (0);
}

static char	*ft_check(int n, char *num)
{
	if (n == 0)
		num = ft_strdup("0");
	else
		num = ft_strdup("-2147483648");
	return (num);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		use[3];

	use[0] = 0;
	use[1] = 0;
	num = NULL;
	if (n == -2147483648 || n == 0)
		return (num = ft_check(n, num));
	else if (n < 0)
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
