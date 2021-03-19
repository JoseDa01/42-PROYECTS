/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:43:51 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/17 18:02:16 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADRT_H
# define LOADRT_H
# include "../minirt.h"

int				loadscene(t_scene *scene, char *args_file);
void			processdata(t_scene *scene, char **comp, char *line);
void			loadresol(t_scene *scene, char **comp);
void			loadcam(t_scene *scene, char **comp);
void			loadamlight(t_scene *scene, char **comp);
void			loadlight(t_scene *scene, char **comp);
void			loadsphere(t_scene *scene, char **comp);
t_vector		loadpoint(char *point);
t_rgbcolor		loadcolor(char *color);
t_vector		loadvector(char *vector);
int				compcounter(char **comp);
void			freecomps(char **comp);
void			addobject(t_scene *scene, void *object);
float			ft_atof(char *str);
void			init_camera(t_camera *cam, t_resol resol);
#endif