/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorrt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:45:08 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:53:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORRT_H
# define COLORRT_H
# include "../minirt.h"

t_color			anglecolor(t_color color, t_vect3 normal, t_vect3 raydir);
t_color			reflectedcolor(t_color colorobject, t_color colorlight);
t_color			intensitycolor(t_color color, double intensity);
unsigned int	colortoint(t_color color);
t_color			addcolor(t_color color1, t_color color2);
t_color			fusion_colors(t_colors_reflected colors);
t_color			calccolor(t_intersection *intersection, t_rayo ray, double intesity, t_color colorlight);
t_color			ambientlight(t_scene *scene, t_intersection *intersection);

#endif