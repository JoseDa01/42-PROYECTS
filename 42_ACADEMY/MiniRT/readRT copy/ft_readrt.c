/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:19:20 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/17 17:22:14 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readrt.h"

t_file	readargs(int argc, char **argv)
{
	t_file argfile;

	ft_bzero(&argfile, sizeof(t_file));
	if(argc >= 2)
	{
		if (strncmp(&argv[1][ft_strlen(argv[1]) - 3], ".rt", 3) == 0)
		{
			argfile.args_file = ft_strdup(argv[1]);
			if (argc < 3)
				return (argfile);
			if (strncmp(argv[2], "--save", 6) == 0)
			{
				if (argc == 3)
					argfile.save_file = ft_strdup("scene.bmp");
				else if (argc == 4)
					argfile.save_file = ft_strjoin(argv[3], ".bmp");
				else
					printf("ERROR\nHa excedido el numero maximo de argumentos\n");
			}
			else
				printf("ERROR\nPara guardar la escena debe añadir la extension --save\n");
		}
		else
			printf("ERROR\nEl fichero debe tener el formato .rt\n");
	}
	else
		printf("ERROR\nSe necista un fichero para cargar la escena\n");
	return(argfile);
}