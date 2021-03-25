/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 02:48:07 by marvin            #+#    #+#             */
/*   Updated: 2021/03/25 02:48:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "../generateimagert.h"

t_bmp_file		inibmp(char *name, unsigned short int bitperpixel, t_resolution resolution);
void			writebmp(int fd, char *image, t_bmp_file file);
void			imagetofile(char *rgbmatrix, char *name, t_resolution resolution);
#endif