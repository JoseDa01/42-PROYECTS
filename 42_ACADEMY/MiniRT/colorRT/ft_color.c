/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:44:43 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:51:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorrt.h"

t_color			intensitycolor(t_color color, double intensity)
{
	t_color color1;

	color1.red = color.red * intensity;
	color1.green = color.green * intensity;
	color1.blue = color.blue * intensity;
	return (color1);
}

t_color			anglecolor(t_color color, t_vect3 normal, t_vect3 raydir)
{
	double cos;

	cos = angletwovectors(normal, raydir);
	if (cos < 0)
		ft_bzero(&color, sizeof(color));
	color.red *= cos;
	color.green *= cos;
	color.blue *= cos;
	return (color);
}

t_color			reflectedcolor(t_color colorobject, t_color colorlight)
{
	t_color refcolor;

	refcolor.intensity = 0;
	refcolor.red = (colorlight.red * colorobject.red) / 255;
	refcolor.green = (colorlight.green * colorobject.green) / 255;
	refcolor.blue = (colorlight.blue * colorobject.blue) / 255;
	return (refcolor);
}

t_color			calccolor(t_intersection *intersection, t_rayo ray, double intesity, t_color colorlight)
{
	t_color color;

	color = reflectedcolor(intersection->color, colorlight);
	color = anglecolor(color, intersection->normal, ray.vector);
	color = intensitycolor(color, intesity);
	return (color);
}

t_color			ambientlight(t_scene *scene, t_intersection *intersection)
{
	t_color	new_color;

	ft_bzero(&new_color, sizeof(new_color));
	new_color = reflectedcolor(intersection->color, scene->env_light.color);
	new_color = intensitycolor(new_color, scene->env_light.intensity);
	return (new_color);
}

t_color			addcolor(t_color color1, t_color color2)
{
	t_color color;

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

unsigned int	colortoint(t_color color)
{
	unsigned int color_int;

	color_int = 0;
	color_int += color.red * pow(256, 2);
	color_int += color.green * pow(256, 1);
	color_int += color.blue;
	return (color_int);
}

t_color			fusion_colors(t_colors_reflected colors)
{
	t_color color;

	color = addcolor(colors.color_ambient, colors.color_lights);
	return (color);
}