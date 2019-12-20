/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:19:43 by jtello-m          #+#    #+#             */
/*   Updated: 2019/12/12 20:40:50 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

int				get_next_line(int fd, char **line);
int				ft_check(int sr, int fd, char **s, char **line);
int				ft_printline(char **s, char **line);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_substr(char const *str, unsigned int start, size_t n);
void			*ft_strchr(const char *s, int c);
char			*ft_newstr(int size);
void			ft_delete(char **as);
int				ft_strlen(const char *str);
#endif
