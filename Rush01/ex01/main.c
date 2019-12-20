/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clostao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:17:44 by clostao-          #+#    #+#             */
/*   Updated: 2019/09/16 10:58:30 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

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

int					main(int n_args, char **args)
{
	struct s_table		tabla;
	int					coordenadas[2];
	struct s_requires	requires;

	if (n_args == 2)
	{
		clean_matrix(&tabla);
		requires = str_to_intab_conversor(args[1], &requires);
		coordenadas[0] = 0;
		coordenadas[1] = 0;
		tabla = *solve_skyscraper(&tabla, coordenadas, 4, requires.req);
		if (tabla.matrix[0][0] == -1)
		{
			ft_putstr("No hay solución posible para los datos de entrada");
		}
		else
		{
			print_matrix(&tabla);
		}
	}
	else
	{
		ft_putstr("El programa debe tener un solo parametro de entrada");
	}
}
