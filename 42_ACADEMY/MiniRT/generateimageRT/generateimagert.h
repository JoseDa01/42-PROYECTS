/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generateimagert.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:23:17 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 13:39:08 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATEIMAGERT_H
# define GENERATEIMAGERT_H
# include "../minirt.h"
# include "bmp/bmp.h"

void				generateimage(t_scene scene, t_libx *libx);
void				inicamera(t_camera *camera, t_resolution resolution);
t_intersection		*raycollision(t_list_obj *objects, t_rayo ray);
t_intersection		*primaryray(t_scene *scene, t_rayo *ray, int pixelx, int pixelj);
t_color				secondaryray(t_scene *scene, t_rayo ray, t_intersection *intersectionobject);
void				writepixelimage(t_libx *libx, t_color color, int x, int y);
t_rayo				cordtoray(int i, int j, t_scene *scene);
t_rayo				raytolight(t_intersection *intersection, t_rayo primary, t_light_point light);
t_intersection		*returnnear(t_intersection *first, t_intersection *second);
t_intersection		*infront(t_intersection *intersection);
int					changecamera(t_scene *scene, int next);
#endif