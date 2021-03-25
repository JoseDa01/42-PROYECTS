/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:14:57 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:38:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXRT_H
# define LIBXRT_H
# include "../minirt.h"

void		libx_init(t_data *sdata);
int			key_pressed(int key, t_data *sdata);
int			mouse_hook(int button, int x, int y, t_data libx_param);

#endif