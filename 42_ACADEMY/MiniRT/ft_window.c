/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:07:17 by jtello-m          #+#    #+#             */
/*   Updated: 2021/02/09 12:27:51 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		length;
	int		end;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void){

	void *mlx;
	void *mlx_win;
	t_data	img;
	int i = 0;
	int j = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Future MiniRT");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.length, &img.end);

	/*	while (j < 1080)
		{
			while (i < 1920)
			{
				if((((i * i) - (50000)) + ((j * j)- (50000))) == 25)
				{
					my_mlx_pixel_put(&img, i, j, 0x00BE00DE);
				}
				i++;
			}
			i = 0;
			j++;
		}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);

		mlx_loop(mlx);*/
}

//gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit ft_window.c
//empezar a imprimir figuras