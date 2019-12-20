/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:55:53 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/22 22:07:54 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			ft_strlen(char *str);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_mil_str(int i);
char		*ft_zeros(char *str);
void		ft_cut(char *str, char **cut, int i, int max);
void		ft_putstr(char *str);
int			ft_search_zeros(char *str);
int			ft_error(char *file);

int			ft_error(char *file)
{
	int dicc;
	int aux;

	aux = 0;
	dicc = open(file, O_RDONLY);
	if (dicc == -1)
	{
		aux = 1;
	}
	close(dicc);
	return (aux);
}

void		lectura(char *str, char *file)
{
	int		flag;
	int		i;
	int		dicc;
	char	buf;

	flag = 0;
	dicc = open(file, O_RDONLY);
	while (flag == 0)
	{
		i = 0;
		read(dicc, &buf, 1);
		while (str[i++] == buf)
			read(dicc, &buf, 1);
		i--;
		if (str[i] == '\0')
			flag = 1;
	}
	while (buf == ' ' || buf == ':')
		read(dicc, &buf, 1);
	while (buf != '\n')
	{
		write(1, &buf, 1);
		read(dicc, &buf, 1);
	}
	close(dicc);
}
