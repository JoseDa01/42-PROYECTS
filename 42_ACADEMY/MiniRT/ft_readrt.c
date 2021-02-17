/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:19:20 by jtello-m          #+#    #+#             */
/*   Updated: 2021/02/17 10:26:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		readrt(int fd)
{
	int i;
	char *line;

	while ((i = get_next_line(fd, &line)) > 0)
		{
			if ((i = type_rt(line)) < 0)
				return (NULL);
			free(line);
		}
}

int			type_rt(char *line)
{
	if (line[0] != '\0')
	{
		if (line[0] == 'R')
			return (pruebas(line));
		else if (line[0] == 'A')
			return (pruebas(line));
		else if (line[0] == 'c' && line[1] == 'y')
			return (pruebas(line));
		else if (line[0] == 'c')
			return (pruebas(line));
		else if (line[0] == 'l')
			return (pruebas(line));
		else if (line[0] == 's' && line[1] == 'p')
			return (pruebas( line));
		else if (line[0] == 's' && line[1] == 'q')
			return (pruebas(line));
		else if (line[0] == 'p' && line[1] == 'l')
			return (pruebas(line));
		else if (line[0] == 't' && line[1] == 'r')
			return (pruebas(line));
		else
			return (-1);
	}
	return (0);
}