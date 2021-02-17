/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:29:29 by jtello-m          #+#    #+#             */
/*   Updated: 2021/02/17 10:14:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <stdlib.h>

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

t_vector		*cross(t_vector u, t_vector v);
t_vector		*product_scalar(t_vector u, t_vector v);
t_vector		*add_vectors(t_vector v1, t_vector v2);
t_vector		*subtract_vectors(t_vector v1, t_vector v2);
t_vector		*multiply_vectors_rotation(t_vector r, t_vector v2);
t_vector		*multiply_vectors(float k, t_vector v2);
float			length_vectors(t_vector v);
float			distance_points(t_vector p1, t_vector p2);
float			product_vectors(t_vector v1, t_vector v2);

#endif