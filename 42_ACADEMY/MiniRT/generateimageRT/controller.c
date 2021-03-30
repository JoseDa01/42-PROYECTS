/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:46:28 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 20:24:37 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generateimage.h"

t_color	calccolor(t_intersection *inter, t_rayo ray, double inten, t_color col)
{
	t_color	color;

	color = reflectedcolor(inter->color, col);
	color = anglecolor(color, inter->normal, ray.vector);
	color = intensitycolor(color, inten);
	return (color);
}

t_color	ambientlight(t_scene *scene, t_intersection *intersection)
{
	t_color	new_color;

	ft_bzero(&new_color, sizeof(new_color));
	new_color = reflectedcolor(intersection->color, scene->env_light.color);
	new_color = intensitycolor(new_color, scene->env_light.intensity);
	return (new_color);
}

void	writepixelimage(t_libx *libx, t_color color, int x, int y)
{
	int	bitpixel;
	int	size_line;
	int	endian;

	libx->img_addr = (int *)mlx_get_data_addr(libx->img_ptr,
			&bitpixel, &size_line, &endian);
	libx->img_addr[(size_line / 4) *y + x] = colortoint(color);
	mlx_pixel_put(libx->ptr, libx->win_ptr, x, y, colortoint(color));
}

void	showscene(t_libx *libx, t_arg *args, t_scene *scene)
{
	if (args->file_save == NULL)
		mlx_put_image_to_window(libx->ptr, libx->win_ptr, libx->img_ptr, 0, 0);
	else
		imagetofile((char *)libx->img_addr, args->file_save, scene->resolution);
	mlx_destroy_image(libx->ptr, libx->img_ptr);
}

void	generateimage(t_scene sc, t_libx *libx)
{
	int					i;
	int					j;
	t_intersection		*intersection;
	t_colors_reflected	colors;
	t_rayo				ray;

	libx->img_ptr = mlx_new_image(libx->ptr, sc.resolution.x, sc.resolution.y);
	ft_bzero(&colors, sizeof(t_colors_reflected));
	i = 0;
	j = 0;
	while (i < sc.resolution.y)
	{
		while (j < sc.resolution.x)
		{
			intersection = primaryray(&sc, &ray, j, i);
			if (intersection != NULL)
			{
				colors.color_lights = secondaryray(&sc, ray, intersection);
				colors.color_ambient = ambientlight(&sc, intersection);
				writepixelimage(libx, fusion_colors(colors), j, i);
			}
			if (intersection != NULL)
				free(intersection);
			j++;
		}
		i++;
		j = 0;
	}
}
