/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:44:43 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 14:02:57 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorrt.h"

t_rgbcolor			intenscolor(t_rgbcolor color, float intens)
{
	t_rgbcolor		intens_color;

	intens_color.red = color.red * intens;
	intens_color.green = color.green * intens;
	intens_color.blue = color.blue * intens;
	return (intens_color);
}

t_rgbcolor			anglecolor(t_rgbcolor color, t_vector objvector, t_vector rayvector)
{
	float			cos;

	cos = angle2vects(objvector, rayvector);
	if (cos < 0)
		ft_bzero(&color, sizeof(t_rgbcolor));
	color.red *= cos;
	color.green *= cos;
	color.blue *= cos;
	return (color);
}

t_rgbcolor			reflectedcolor(t_rgbcolor colorobj, t_rgbcolor lightcolor)
{
	t_rgbcolor		refcolor;

	refcolor.intens = 0;
	refcolor.red = (lightcolor.red * colorobj.red) / 255;
	refcolor.green = (lightcolor.green * colorobj.green) / 255;
	refcolor.blue = (lightcolor.blue * colorobj.blue) / 255;
	return (refcolor);
}

t_rgbcolor			calcolor(t_intersection *intersection, t_ray ray, float intens, t_rgbcolor lightcolor)
{
	t_rgbcolor		color;

	color = reflectedcolor(intersection->color, lightcolor);
	color = anglecolor(color, intersection->normalvect, ray.direction);
	color = intenscolor(color, intens);
	return (color);
}

t_rgbcolor			ambienlight(t_scene *scene, t_intersection *intersection)
{
	t_rgbcolor		am_color;

	ft_bzero(&am_color, sizeof(t_rgbcolor));
	am_color = reflectedcolor(intersection->color, scene->am_light.color);
	am_color = intenscolor(am_color, scene->am_light.luminosity);
	return (am_color);
}

t_rgbcolor			addcolor(t_rgbcolor color1, t_rgbcolor color2)
{
	t_rgbcolor color;

	if (color1.intens + color2.intens > 255)
		color.intens = 255;
	else
		color.intens = color1.intens + color2.intens;
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

int					colortoint(t_rgbcolor color)
{
	int int_color;

	int_color = 0;
	int_color += color.red * pow(256,2);
	int_color += color.green * pow(256, 1);
	int_color += color.blue;
	return (int_color);
}

t_rgbcolor			fusion_colors(t_all_colors colors)
{
	t_rgbcolor color;

	color = addcolor(colors.color_lights, colors.color_am);
	return (color);
}