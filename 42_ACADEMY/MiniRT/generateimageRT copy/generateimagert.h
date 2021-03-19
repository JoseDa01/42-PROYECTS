/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generateimagert.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:23:17 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 14:14:41 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATEIMAGERT_H
# define GENERATEIMAGERT_H
# include "../minirt.h"

void				raytracing(t_scene scene, t_libx *libx);
t_intersection		*primaryray(t_scene *scene, t_ray *ray, int pixelx, int pixely);
t_rgbcolor			secondaryray(t_scene *scene, t_ray raycam, t_intersection *intersection);
t_ray				cordtoray(int pixelx, int pixely, t_scene *scene);
t_intersection		*raycollision(t_list_objects *object, t_ray ray);
t_ray				raytolight(t_intersection *intersection, t_ray primary, t_light light);
t_intersection		*returnnear(t_intersection *first, t_intersection *second);
t_intersection		*behindcam(t_intersection *intersection);
void				writepixelimg(t_libx *libx, t_rgbcolor color, int x, int y);
#endif