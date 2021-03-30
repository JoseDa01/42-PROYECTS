/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:22:48 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/29 20:23:20 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

unsigned int	colortoint(t_color color)
{
	unsigned int	color_int;

	color_int = 0;
	color_int += color.red * pow(256, 2);
	color_int += color.green * pow(256, 1);
	color_int += color.blue;
	return (color_int);
}

t_color	fusion_colors(t_colors_reflected colors)
{
	t_color	color;

	color = addcolor(colors.color_ambient, colors.color_lights);
	return (color);
}
