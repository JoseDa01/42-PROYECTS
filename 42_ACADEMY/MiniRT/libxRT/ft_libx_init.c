/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:13:43 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:40:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxrt.h"

int		key_pressed(int key, t_data_struct *data)
{
	int changed;

	changed = 0;
	if (key == ESC)
		exit(0);
	if (key == 123 || key == 124)
	{
		if (key == 123)
			changed = changecamera(&data->scene, 0);
		else if (key == 124)
			changed = changecamera(&data->scene, 1);
		if (changed == 1)
		{
			generateimage(data->scene, &data->libx);
			showscene(&data->libx, &data->args, &data->scene);
		}
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_libx *param)
{
	printf("button pulsado %d\n", button);
	printf("pixel selecionado =  %d x %d\n", x, y);
	printf("direcion a win ptr %p\n", param->win_ptr);
	return (0);
}

void	ini_libx(t_data_struct *data)
{
	data->libx.ptr = mlx_init();
	data->libx.win_ptr = mlx_new_window(data->libx.ptr, data->scene.resolution.x, data->scene.resolution.y, "raytracing majestuoso");
	mlx_do_key_autorepeatoff(data->libx.ptr);
	mlx_hook(data->libx.win_ptr, 2, 1, key_pressed, &data->scene);
	mlx_mouse_hook(data->libx.win_ptr, &mouse_hook, &data->libx);