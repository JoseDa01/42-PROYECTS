/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amolin-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:55:30 by amolin-m          #+#    #+#             */
/*   Updated: 2019/09/22 22:58:29 by amolin-m         ###   ########.fr       */
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

int		ft_strlen(char *str)
{
	int	contador;

	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	return (contador);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_cut(char *str, char **cut, int i, int locat)
{
	int longi;

	longi = ft_strlen(str) - 1;
	*cut = malloc(i + 1);
	ft_strncpy(*cut, &str[longi - locat], i);
	if (i == 2)
	{
		cut[0][1] = '0';
	}
}

char	*ft_mil_str(int i)
{
	char	*milles;
	int		x;

	x = 1;
	milles = malloc(3 * i + 2);
	milles[0] = '1';
	while (x < 3 * i + 1)
	{
		milles[x] = '0';
		x++;
	}
	milles[x] = '\0';
	return (milles);
}
