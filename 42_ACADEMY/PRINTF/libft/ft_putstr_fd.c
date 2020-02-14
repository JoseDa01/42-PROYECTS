/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:58:39 by jtello-m          #+#    #+#             */
/*   Updated: 2019/11/14 18:24:43 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int contador;
	int longitud;

	if (str == NULL)
		return ;
	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	longitud = contador;
	contador = 0;
	while (contador < longitud)
	{
		write(fd, &str[contador], 1);
		contador++;
	}
}
