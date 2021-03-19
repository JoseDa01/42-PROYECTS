/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:59:48 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 17:45:20 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int		main(int argc, char **argv)
{
	t_data	sdata;
	
	sdata.argfile = readargs(argc, argv);
	loadscene(&sdata.scene, sdata.argfile.args_file);
	libx_init(&sdata);
	raytracing(sdata.scene, &sdata.libx);
	showimage(&sdata.libx, &sdata.argfile, &sdata.scene);
	if (sdata.argfile.save_file == NULL)
		mlx_loop(sdata.libx.mlx);
	return(0);
}