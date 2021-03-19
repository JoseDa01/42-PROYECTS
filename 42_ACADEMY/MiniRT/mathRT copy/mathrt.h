/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:59:42 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 13:46:16 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHRT_H
# define MATHRT_H
# include "../minirt.h"

t_vector			addvect(t_vector vect1, t_vector vect2);
t_vector			multvect(t_vector vector, float nb);
t_vector			pointray(t_ray ray, float dist);
t_vector			distvect(t_vector pt1, t_vector pt2);
t_vector			crossproduct(t_vector a, t_vector b);
t_vector			changelenght(t_vector vector, float module);
t_tupla				notableproduct(float a, float b);
t_tupla				addtupla(t_tupla a, t_tupla b);
float				lowernb(t_tupla tupla);
float				distancept(t_vector point1, t_vector point2);
t_vector			perpendicular_rand_vect(t_vector vector);
float				modulevector(t_vector vector);
float				angle2vects(t_vector vector1, t_vector vector2);
t_tupla				solvequation(t_tupla equation, float nb);
t_tupla				solvequation1(t_tupla equation, float nb);
t_tupla				solvequation2(t_tupla equation, float nb);
#endif