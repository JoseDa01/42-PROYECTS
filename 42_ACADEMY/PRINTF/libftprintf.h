/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:46:56 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/23 07:43:56 by jtello-m         ###   ########.fr       */
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
	int				i;
	int				j;
	int				chcount;
	int				flag0;
	int				flagm;
	int				flagp;
	int				flags;
	int				nflags;
	int				flag_is_negative;
	int				nbr;
	int				nbrm;
	int				nbr0;
	int				nbrp;
	int				large;
	int				tam;
	int				tam_p;
	char			a;
	char			*s;
	int				n;
	unsigned long	p;
	char			*p_str;
	char			*n_str;
	char			*hex_str;
	unsigned int	u;
	char			*u_str;
	unsigned int	hex;
}				t_var;

int				ft_printf(const char *str, ...);
void			ft_flags(const char *str, t_var *count, va_list fa);
void			ft_format(const char *str, t_var *count,
va_list fa, size_t ppos);
void			ft_flags(const char *str, t_var *count, va_list fa);
int				ft_check_flags(const char *str, t_var *count, va_list fa);
void			assig_nbr(const char *str, t_var *count);
void			ft_starflag(const char *str, t_var *count, va_list fa);
void			ft_app_flags(const char *str, t_var *count);
void			ft_flag_minus(t_var *count);
void			ft_ptr(const char *p_str, t_var *count);
void			ft_args_ptr(const char *str, t_var *count, va_list fa);
void			ft_str(t_var *count);
void			ft_prec_str(t_var *count);
void			ft_args_str(const char *str, t_var *count, va_list fa);
void			ft_char(t_var *count);
void			ft_args_c(char const *str, t_var *count, va_list fa);
void			ft_int(char *str_int, t_var *count);
void			ft_args_int(const char *str, t_var *count, va_list fa);
void			ft_hex(const char *hex_str, t_var *count);
void			ft_args_hex(const char *str, t_var *count, va_list fa);
void			ft_pct(t_var *count);
void			ft_args_pct(const char *str, t_var *count);
void			ft_u(const char *u_str, t_var *count);
void			ft_args_u(const char *str, t_var *count, va_list fa);
void			ft_struc_init(t_var *count);
void			ft_struc_reset(t_var *count);
int				ft_atoi(const char *str, t_var *count);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_base(unsigned long nbr, int base, char *tab);
void			ft_writeflags(int nbr, int tam, int j, t_var *count);
void			ft_writeflags_int(int tam, int j, t_var *count);
void			ft_writeflags_str(int i, char *str, t_var *count);
void			special_cases(t_var *count);
void			starpt(const char *str, t_var *count, va_list fa);
void			starflag_auxnbr0(t_var *count);
void			starflag_auxnbr(t_var *count);
#endif
