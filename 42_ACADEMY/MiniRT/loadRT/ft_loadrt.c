/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:30:40 by jtello-m          #+#    #+#             */
/*   Updated: 2021/03/19 19:17:21 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadrt.h"

void	processdata(t_scene *scene, char **comp, char *line)
{
	if (line[0] == 'R')
		loadresol(scene, comp);
	else if(line[0] == 'A')
		loadamlight(scene, comp);
	else if (line[0] == 'c')
		loadcam(scene, comp);
	else if(line[0] == 'l')
		loadlight(scene, comp);
	else if(line[0] == 's' && line[1] == 'p')
		loadsphere(scene, comp);
	/*else if(line[0] == 'p' && line[1] == 'l')
		loadplane();
	else if(line[0] == 's' && line[1] == 'q')
		loadsquare();
	else if(line[0] == 'c' && line[1] == 'y')
		loadcylinder();
	else if(line[0] == 't' && line[1] == 'r')
		loadtriangle();*/
	else
		printf("ERROR\nNo se ha encontrado ningun objeto\n");
}


int		loadscene(t_scene *scene, char *args_file)
{
	char	*line;
	char	**comp;
	int		fd;
	int		flag;

	flag = 0;
	fd = open(args_file, O_RDONLY);
	if (fd < 0 && args_file != NULL)
	{
		printf("ERROR\nNo se puede abrir el archivo\n");
		exit(-1);
	}
	while (!flag)
	{
		if (get_next_line(fd, &line) == 0)
			flag = 1;
		comp = ft_split(line, ' ');
		if (compcounter(comp) >= 1)
			processdata(scene, comp, line);
		freecomps(comp);
		free(line);
	}
	close(fd);
	return(0);
}