/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectionsrt.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:48:53 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/10 13:41:45 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONSRT_H
# define INTERSECTIONSRT_H
# include "../minirt.h"

t_intersection				*spherecollision(t_ray ray, t_sphere *esfera);

#endif