/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:24:12 by jtello-m          #+#    #+#             */
/*   Updated: 2019/09/15 23:36:24 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

struct				s_table
{
	int matrix[4][4];
};

struct				s_requires
{
	int req[16];
};

struct s_table		*back_error(struct s_table *tab,
						int coords[2], int v, int requires[16]);
struct s_table		*go_forward_solving(struct s_table *tab, int coords[2],
						int v, int requires[]);
void				go_the_back_position(int *i, int *j);
int					check_ext_numbers(struct s_table *tab,
						int coords[2], int requires[16]);
int					check_hor_left(struct s_table *tab,
						int coords[2], int requires[16]);
int					check_hor_right(struct s_table *tab,
						int coords[2], int requires[16]);
int					check_vert_down(struct s_table *tab,
						int coords[2], int requires[16]);
int					check_vert_up(struct s_table *tab,
						int coords[2], int requires[16]);
void				print_matrix(struct s_table *tab);
int					check_col(struct s_table *tab, int coords[2], int v);
int					check_row(struct s_table *tab, int coords[2], int v);
void				print_matrix(struct s_table *tab);
void				ft_putstr(char *c);
void				clean_matrix(struct s_table *tab);
struct s_table		*solve_skyscraper(struct s_table *tab,
						int coords[2], int a, int requires[16]);
struct s_requires	str_to_intab_conversor(char *str, struct s_requires *tab);
#endif
