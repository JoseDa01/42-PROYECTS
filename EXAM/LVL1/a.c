/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:34:18 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/26 21:44:25 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*word_number(a)
{
	int i;

	i = 0;
	while (i < a)
		{
			write (1, &a, 1);
			i++;
		}
	return (0);
}


int main (int argc, char ** argv)
{
	int i;

	(void)argc;

	i = 0;

	while (argv[1][i] != '\0')
	{
		write(1, &argv[1][word_number(i)], 1);
		i++;
	}
}
