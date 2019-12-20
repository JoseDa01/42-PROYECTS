/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:19:11 by jtello-m          #+#    #+#             */
/*   Updated: 2019/12/12 20:42:12 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int					get_next_line(int fd, char **line)
{
	static char		*s[4096];
	char			*aux;
	char			buf[BUFFER_SIZE + 1];
	int				sr;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((sr = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[sr] = '\0';
		if (s[fd] == '\0')
			s[fd] = ft_strdup(buf);
		else
		{
			aux = ft_strjoin(s[fd], buf);
			s[fd] = aux;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ft_check(sr, fd, s, line));
}

int					ft_check(int sr, int fd, char **s, char **line)
{
	if (sr < 0)
		return (-1);
	else if (sr == 0 && s[fd] == NULL)
	{
		*line = strdup("");
		return (0);
	}
	else
		return (ft_printline(&s[fd], line));
}

int					ft_printline(char **s, char **line)
{
	int		i;
	char	*aux;

	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		aux = ft_strdup(&((*s)[i + 1]));
		free(*s);
		*s = aux;
	}
	else
	{
		*line = ft_strdup(*s);
		ft_delete(s);
		return (0);
	}
	return (1);
}

void				ft_delete(char **s)
{
	if (s != NULL && *s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

int					ft_strlen(const char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
