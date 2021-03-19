/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:13:43 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/16 14:13:39 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxrt.h"

int			press_key(int key, t_data *sdata)
{
	(void)sdata;
	if (key == ESC)
		exit(0);
	//falta el salto de camara;
	return(0);
}

int			mouse_hook(int button, int x, int y, t_data libx_param)
{
	printf("boton pulsado %i\n", button);
	printf("Pixel seleccionado : %i x %i\n", x, y);
	printf("La dirrecion del ptr es : %p\n", libx_param.libx.mlx_win);
	return(0);
}

void		libx_init(t_data *sdata)
{
	sdata->libx.mlx = mlx_init();
	sdata->libx.mlx_win = mlx_new_window(sdata->libx.mlx, sdata->scene.resolution.x, sdata->scene.resolution.y, "Amazing MiniRT");
	mlx_do_key_autorepeatoff(sdata->libx.mlx);
	mlx_hook(sdata->libx.mlx_win, 2, 1, press_key, &sdata->scene);
	mlx_mouse_hook(sdata->libx.mlx_win, &mouse_hook, &sdata->libx);
}