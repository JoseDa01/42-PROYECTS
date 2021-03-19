/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxrt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:14:57 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/04 13:12:12 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXRT_H
# define LIBXRT_H
# include "../minirt.h"

void		libx_init(t_data *sdata);
int			press_key(int key, t_data *sdata);
int			mouse_hook(int button, int x, int y, t_data libx_param);

#endif