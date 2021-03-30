/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:21:56 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:39:24 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "../header.h"

t_color			anglecolor(t_color color, t_vect3 normal, t_vect3 raydir);
t_color			reflectedcolor(t_color colorobject, t_color colorlight);
t_color			intensitycolor(t_color color, double intensity);
unsigned int	colortoint(t_color color);
t_color			addcolor(t_color color1, t_color color2);
t_color			fusion_colors(t_colors_reflected colors);
#endif
