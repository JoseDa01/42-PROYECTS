/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:19:09 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:46:36 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

t_arg	process_args(int arg_n, char **arg_s)
{
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	if (arg_n >= 2)
	{
		if (ft_strncmp(&arg_s[1][ft_strlen(arg_s[1]) - 3], ".rt", 3) == 0)
		{
			arg.file_load = ft_strdup(arg_s[1]);
			if (arg_n < 3)
				return (arg);
			if (ft_strncmp(arg_s[2], "--save", ft_strlen(arg_s[2])) == 0)
			{
				if (arg_n == 3)
					arg.file_save = ft_strdup("scene.bmp");
				else
					arg.file_save = ft_strjoin(arg_s[3], ".bmp");
				if (arg_n > 4)
					error("ha excedido la cantidad maxima de argumentos");
			}
		}
		else
			error("el fichero de escena debe ser de extension .rt");
	}
	else
		error("Se necesita un archivo para cargar la escena");
	return (arg);
}
