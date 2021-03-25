/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectionsrt.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:48:53 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 03:01:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONSRT_H
# define INTERSECTIONSRT_H
# include "../minirt.h"

	t_intersection		*circlecollision(t_rayo ray, t_circle *cir);
	t_cylinder			*inicylinder(t_cylinder *cyl);
	void				rotatecollision(t_rayo *ray, t_cylinder *cyl);
	void				ini_tops(t_cylinder *cyl);;
	t_intersection		*cylindercollision(t_rayo ray, t_cylinder *cyl);
	t_vect3				calcnormalcyl(t_cylinder cyl, t_vect3 intersectionpoint, t_matrix3 matrix);
	t_intersection		*cylindercollisiontransformed(t_rayo ray, t_cylinder cyl);
	t_plane				*iniplane(t_plane *plane);
	t_vect3				planenormal(t_plane *pl, t_rayo ray);
	t_intersection		*planecollision(t_rayo ray, t_plane *pl);
	double				pseudointersection(t_rayo ray, t_vect3 point, t_vect3 normal);
	t_intersection		*spherecollision(t_rayo rayo, t_esfera *esfera);
	t_square			*inisquare(t_square *square);
	t_vect3				squarenormal(t_square *sq, t_rayo ray);
	t_intersection		*squarecollision(t_rayo ray, t_square *sq);
	void				initriangle(t_triangle *triangle);
	t_vect3				trinormal(t_triangle *tri, t_rayo ray);
	t_intersection		*trianglecollision(t_rayo ray, t_triangle *tri);

#endif