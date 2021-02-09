/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:20:44 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/25 20:59:44 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	char	*b;

	b = "hello";
	printf("-----------------\n");
	printf("%s--%c--%p--%d--%i--%x--%X--%u--%%--%s--%c--%p--%d--%i--%x--%X--%u--%%--\n", b, 'c', &b, 123, 987, 54321, 3523, -2,  b, 'c', &b, 123, 987, 54321, 3523, -2);
	ft_printf("%s--%c--%p--%d--%i--%x--%X--%u--%%--%s--%c--%p--%d--%i--%x--%X--%u--%%--\n", b, 'c', &b, 123, 987, 54321, 3523, -2,  b, 'c', &b, 123, 987, 54321, 3523, -2);
	printf("-----------------\n");
	system("leaks a.out");
}