/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:59:48 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/25 02:42:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int				main(int arg_n, char **arg_s)
{
	t_data_struct data;

	data.args = process_args(arg_n, arg_s);
	loadscene(&data.scene, data.args.file_load);
	ini_libx(&data);
	generateimage(data.scene, &data.libx);
	showscene(&data.libx, &data.args, &data.scene);
	if (data.args.file_save == NULL)
		mlx_loop(data.libx.ptr);
	return (0);
}