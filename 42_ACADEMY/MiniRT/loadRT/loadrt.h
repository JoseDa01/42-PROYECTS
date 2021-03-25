/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:51 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:36:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADRT_H
# define LOADRT_H
# include "../minirt.h"

int				loadscene(t_scene *scene, char *filename);
void			processstring(t_scene *scene, char **words);
void			loadtriangle(t_scene *scene, char **words);
void			loadcylinder(t_scene *scene, char **words);
void			loadsquare(t_scene *scene, char **words);
void			loadplane(t_scene *scene, char **words);
void			loadsphere(t_scene *scene, char **words);
void			loadlight(t_scene *scene, char **words);
void			loadcamera(t_scene *scene, char **words);
void			loadresolution(t_scene *scene, char **words);
void			loadambientlight(t_scene *scene, char **words);
t_vect3			chargenormalizedvector(char *vector);
t_color			chargecolor(char *rgb);
t_vect3			chargepoint(char *point);
void			addobject(t_scene *scene, void *object);
int				countwords(char **words);
void			freespace(char **words);
void			error(char *s);
int				fundamentalsobjects(char *str);
void			init_camera(t_camera *cam, t_resol resol);
#endif