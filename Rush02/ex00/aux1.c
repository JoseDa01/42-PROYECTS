/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amolin-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:55:41 by amolin-m          #+#    #+#             */
/*   Updated: 2019/09/22 22:48:59 by amolin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_mil_str(int i);
char	*ft_zeros(char *str);
void	ft_cut(char *str, char **cut, int i, int max);
void	ft_putstr(char *str);
int		ft_search_zeros(char *str);
int		ft_error(char *file);

char	*ft_zeros(char *str)
{
	int		x;
	int		max;
	char	*aux;
	int		j;

	max = ft_strlen(str);
	x = 0;
	while (str[x] == '0')
	{
		x++;
	}
	aux = malloc(max - x + 1);
	j = 0;
	while (x < max)
	{
		aux[j] = str[x];
		j++;
		x++;
	}
	aux[j] = '\0';
	return (aux);
}

void	ft_putstr(char *str)
{
	int contador;
	int longitud;

	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	longitud = contador;
	contador = 0;
	while (contador < longitud)
	{
		write(1, &str[contador], 1);
		contador++;
	}
}

int		ft_str_is_numeric(char *str)
{
	int i;
	int cadena;

	i = 0;
	cadena = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			cadena = 0;
		i++;
	}
	return (cadena);
}

int		ft_search_zeros(char *str)
{
	int i;
	int aux;

	aux = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
		{
			aux = 0;
		}
		i++;
	}
	return (aux);
}
