/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:31:34 by gmartine          #+#    #+#             */
/*   Updated: 2021/03/30 18:39:05 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "../generateimage.h"

t_bmp_file		inibmp(char *name, unsigned short int bitperpixel, t_resolution resolution);
void			writebmp(int fd, char *image, t_bmp_file file);
void			imagetofile(char *rgbmatrix, char *name, t_resolution resolution);
#endif
