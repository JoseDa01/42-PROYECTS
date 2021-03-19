/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorrt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:45:08 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 13:44:23 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORRT_H
# define COLORRT_H
# include "../minirt.h"

t_rgbcolor			calcolor(t_intersection *intersection, t_ray ray, float intens, t_rgbcolor lightcolor);
t_rgbcolor			reflectedcolor(t_rgbcolor colorobj, t_rgbcolor lightcolor);
t_rgbcolor			anglecolor(t_rgbcolor color, t_vector objvector, t_vector rayvector);
t_rgbcolor			intenscolor(t_rgbcolor color, float intens);
t_rgbcolor			addcolor(t_rgbcolor color1, t_rgbcolor color2);
t_rgbcolor			ambienlight(t_scene *scene, t_intersection *intersection);
int					colortoint(t_rgbcolor color);
t_rgbcolor			fusion_colors(t_all_colors colors);

#endif