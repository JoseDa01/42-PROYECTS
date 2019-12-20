/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:55:25 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/22 23:20:21 by jtello-m         ###   ########.fr       */
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
void		programa(char *str, char *file);
int			ft_str_is_numeric(char *str);
int			first_main(int argc, char *str, char *file);
int			aux_main();
int			second_main(int argc, char *str, char *file);

int			main(int argc, char **argv)
{
	char	*str;
	char	*file;
	int		flag;

	flag = 0;
	str = argv[1];
	file = "numbers.dict.txt";
	while (flag == 0)
	{
		second_main(argc, str, file);
		file = argv[1];
		str = argv[2];
		if (ft_str_is_numeric(str) == 1)
		{
			first_main(argc, str, file);
		}
		else
		{
			ft_putstr("ERROR");
		}
		write(1, "\n", 1);
		return (0);
	}
	flag++;
}

int			first_main(int argc, char *str, char *file)
{
	if (argc == 3)
	{
		if (ft_error(file) == 1)
		{
			ft_putstr("ERROR");
			write(1, "\n", 1);
			return (0);
		}
		if (ft_search_zeros(str) == 1)
		{
			ft_putstr("zero");
			write(1, "\n", 1);
			return (0);
		}
		else
		{
			programa(str, file);
		}
	}
	return (0);
}

int			aux_main(void)
{
	ft_putstr("zero");
	write(1, "\n", 1);
	return (0);
}

int			second_main(int argc, char *str, char *file)
{
	if (ft_search_zeros(str) == 1)
	{
		aux_main();
	}
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_str_is_numeric(str) == 1)
	{
		if (argc == 2)
		{
			programa(str, file);
			write(1, "\n", 1);
			return (0);
		}
	}
	return (0);
}
