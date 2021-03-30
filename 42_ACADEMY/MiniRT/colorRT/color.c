/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:46:07 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:39:23 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	anglecolor(t_color color, t_vect3 normal, t_vect3 raydir)
{
	double	cos;

	cos = angletwovectors(normal, raydir);
	if (cos < 0)
		ft_bzero(&color, sizeof(color));
	color.red *= cos;
	color.green *= cos;
	color.blue *= cos;
	return (color);
}

t_color	reflectedcolor(t_color colorobject, t_color colorlight)
{
	t_color	refcolor;

	refcolor.intensity = 0;
	refcolor.red = (colorlight.red * colorobject.red) / 255;
	refcolor.green = (colorlight.green * colorobject.green) / 255;
	refcolor.blue = (colorlight.blue * colorobject.blue) / 255;
	return (refcolor);
}

t_color	intensitycolor(t_color color, double intensity)
{
	t_color	color1;

	color1.red = color.red * intensity;
	color1.green = color.green * intensity;
	color1.blue = color.blue * intensity;
	return (color1);
}

t_color	addcolor(t_color color1, t_color color2)
{
	t_color	color;

	if (color1.intensity + color2.intensity > 255)
		color.intensity = 255;
	else
		color.intensity = color1.intensity + color2.intensity;
	if (color1.red + color2.red > 255)
		color.red = 255;
	else
		color.red = color1.red + color2.red;
	if (color1.green + color2.green > 255)
		color.green = 255;
	else
		color.green = color1.green + color2.green;
	if (color1.blue + color2.blue > 255)
		color.blue = 255;
	else
		color.blue = color1.blue + color2.blue;
	return (color);
}
