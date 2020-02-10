/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:46:56 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/10 17:24:12 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
typedef	struct	s_var
{
	int i; //contador del main str
	int j;
	int a;
	int b;
	int chcount;
	int flag0;
	int flagm;
	int flagp; 
	int flags;
	int nflags;
	int nbr;
	int large;
	int tam;
	char *s;
	char *p;
}				t_var;


int				ft_printf(const char *str, ...);
void			ft_flags(const char *str, t_var *count, va_list fa);
void			ft_format(const char *str, t_var *count, va_list fa);
void			ft_flags(const char *str, t_var *count, va_list fa);
int				ft_check_flags(const char *str, t_var *count);
void			ft_app_flags(const char *str, t_var *count);
void			ft_flag_minus(t_var *count);
void			ft_ptr(t_var *count);
void			ft_args_ptr(const char *str, t_var *count, va_list fa);
void			ft_str(t_var *count);
void			ft_prec_str(t_var *count);
void			ft_args_str(const char *str, t_var *count, va_list fa);
void			ft_char(t_var *count);
void			ft_args_c(t_var *count, va_list fa);
void			ft_struc_init(t_var *count);
void			ft_struc_reset(t_var *count);
int				ft_atoi(const char *str, t_var *count);
#endif