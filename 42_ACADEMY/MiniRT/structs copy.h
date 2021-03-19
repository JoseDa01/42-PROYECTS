/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:17:49 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/17 18:37:15 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	originpt;
	t_vector	direction;
}				t_ray;

typedef struct	s_tupla
{
	int			tamaño;
	float		tupla[3];
}				t_tupla;

typedef struct	s_rgbcolor
{
	float	intens;
	int		red;
	int		green;
	int		blue;
}				t_rgbcolor;

typedef struct		s_all_colors
{
	t_rgbcolor	color_lights;
	t_rgbcolor	color_am;
}					t_all_colors;

typedef struct	s_intersection
{
	float		dist;
	void		*object;
	t_vector	normalvect;
	t_rgbcolor	color;
}				t_intersection;

typedef struct	s_sphere
{
	t_vector	point;
	float		radio;
	t_rgbcolor	color;
}				t_sphere;

typedef enum			e_object
{
	sphere,
	square,
	plane,
	cylinder,
	triangle,
	circle
}						t_object;

typedef struct	s_list_objects
{
	void					*object;
	void					*functioncoll;
	t_object				type;
	struct s_list_objects	*next;
}				t_list_objects;

typedef struct	s_light
{
	t_vector	light_point;
	float		luminosity;
	t_rgbcolor	color;
}				t_light;

typedef struct	s_list_lights
{
	t_light					light;
	struct s_list_lights	*next;
}				t_list_lights;

typedef struct	s_ambien_light
{
	float	luminosity;
	t_rgbcolor	color;
}				t_ambien_light;

typedef struct	s_camera
{
	t_vector			origin_point;
	t_vector			direction;
	t_vector			vectorx;
	t_vector			vectory;
	float				fov;
	float				fov_rad;
	float				depth;
	struct s_camera		*next;
	struct s_camera		*back;
}				t_camera;

typedef struct	s_resol
{
	int		x;
	int		y;
}				t_resol;

typedef struct	s_scene
{
	t_list_objects	*objects;
	t_list_lights	*lights;
	t_ambien_light	am_light;
	t_camera		*camera;
	t_resol			resolution;
}				t_scene;

typedef struct	s_img_data
{
	int			bits_per_pixel;
	int			length;
	int			end;
}				t_img_data;

typedef struct	s_libx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			*img_addr;
	t_img_data	img_data;
}				t_libx;

typedef struct	s_file
{
	char	*args_file;
	char	*save_file;
}				t_file;

typedef struct	s_data
{
	t_file		argfile;
	t_scene		scene;
	t_libx		libx;
}				t_data;

#endif