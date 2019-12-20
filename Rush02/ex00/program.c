/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amolin-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:42:08 by amolin-m          #+#    #+#             */
/*   Updated: 2019/09/22 23:46:11 by amolin-m         ###   ########.fr       */
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
void		lectura(char *str, char *file);

void		programa(char *str, char *file)
{
	int		max;
	int		miles;
	int		flag;
	int		locat;
	char	*cut;

	flag = 1;
	str = ft_zeros(str);
	max = ft_strlen(str) - 1;
	locat = max;
	miles = max / 3;
	while (locat != -1)
	{
		if (locat % 3 == 2)
		{
			if (str[max - locat] != '\0')
			{
				ft_cut(str, &cut, 1, locat);
				if (flag == 0)
				{
					write(1, " ", 1);
				}
				flag = 0;
				lectura(cut, file);
				write(1, " ", 1);
				lectura("100", file);
				free(cut);
			}
			locat--;
		}
		if (locat % 3 == 1)
		{
			if (str[max - locat] > '1')
			{
				ft_cut(str, &cut, 2, locat);
				if (flag == 0)
				{
					write(1, " ", 1);
				}
				flag = 0;
				lectura(cut, file);
				free(cut);
				locat--;
			}
			else if (str[max - locat] == '1')
			{
				ft_cut(str, &cut, 2, locat);
				cut[1] = str[max - locat + 1];
				if (flag == 0)
				{
					write(1, " ", 1);
				}
				flag = 0;
				lectura(cut, file);
				locat = locat - 2;
				free(cut);
			}
			else
			{
				locat--;
			}
		}
		if (locat % 3 == 0)
		{
			if (str[max - locat] != '0')
			{
				ft_cut(str, &cut, 1, locat);
				if (flag == 0)
				{
					write(1, " ", 1);
				}
				flag = 0;
				lectura(cut, file);
				free(cut);
			}
			locat--;
		}
		if (miles != 0 && (str[max - locat - 1] != '0'))
		{
			if (str[max - locat - 2] != '0')
			{
				if (str[max - locat - 3] != '0')
				{
					cut = ft_mil_str(miles);
					write(1, " ", 1);
					lectura(cut, file);
					free(cut);
				}
				miles--;
			}
		}
	}
}
