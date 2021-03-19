/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:26:03 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/17 18:18:20 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "showimagert.h"

void			showimage(t_libx *libx, t_file *argfile, t_scene *scene)
{
	(void)scene;
	if (argfile->save_file == NULL)
		mlx_put_image_to_window(libx->mlx, libx->mlx_win, libx->img, 0, 0);
}