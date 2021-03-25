/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:26:03 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:46:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "showimagert.h"

void			showscene(t_libx *libx, t_arg *args, t_scene *scene)
{
	if (args->file_save == NULL)
		mlx_put_image_to_window(libx->ptr, libx->win_ptr, libx->img_ptr, 0, 0);
	else
		imagetofile((char *)libx->img_addr, args->file_save, scene->resolution);
	mlx_destroy_image(libx->ptr, libx->img_ptr);
}