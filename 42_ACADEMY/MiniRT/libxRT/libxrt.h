/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:14:57 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 13:18:13 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXRT_H
# define LIBXRT_H
# include "../minirt.h"

int		mouse_hook(int button, int x, int y, t_libx *param);
int		key_pressed(int key, t_data_struct *data);
void	ini_libx(t_data_struct *data);

#endif