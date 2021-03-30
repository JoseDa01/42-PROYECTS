/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_vectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:31:57 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/29 19:50:52 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load.h"

t_vect3	chargepoint(char *point)
{
	t_vect3		point1;
	char		**numbers;

	numbers = ft_split(point, ',');
	if (countwords(numbers) != 3)
		error("Mal formato de punts en el espacio");
	point1.x = ft_atoi_double(numbers[0]);
	point1.y = ft_atoi_double(numbers[1]);
	point1.z = ft_atoi_double(numbers[2]);
	freespace(numbers);
	return (point1);
}

t_color	chargecolor(char *rgb)
{
	char		**words;
	t_color		returned;

	words = ft_split(rgb, ',');
	if (countwords(words) != 3)
		error("Mal formato de colores rgb");
	returned.red = ft_atoi(words[0]);
	returned.green = ft_atoi(words[1]);
	returned.blue = ft_atoi(words[2]);
	freespace(words);
	if (!(returned.red >= 0 && returned.red <= 255
			&& returned.green >= 0 && returned.green <= 255
			&& returned.blue >= 0 && returned.blue <= 255))
		error("Los colores en RGB van del 0 al 255");
	return (returned);
}

t_vect3	chargenormalizedvector(char *vector)
{
	t_vect3		vector1;
	char		**numbers;

	numbers = ft_split(vector, ',');
	if (countwords(numbers) != 3)
		error("Mal formato de vector");
	vector1.x = ft_atoi_double(numbers[0]);
	vector1.y = ft_atoi_double(numbers[1]);
	vector1.z = ft_atoi_double(numbers[2]);
	freespace(numbers);
	if (!(vector1.x >= -1 && vector1.x <= 1
			&& vector1.y >= -1 && vector1.y <= 1
			&& vector1.z >= -1 && vector1.z <= 1))
		error("Los componentes de un vector van del -1 al 1");
	if (vector1.x == 0 && vector1.y == 0 && vector1.z == 0)
		error("No puede haber un vector nulo");
	return (vector1);
}
