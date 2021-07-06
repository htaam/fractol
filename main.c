/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:57:56 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/06 18:05:58 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		imgage;
	t_numbers	numbers;
	char		set;

	numbers.x_max = 1920;
	numbers.y_max = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, numbers.x_max, numbers.y_max, "Hello world!");
	imgage.img = mlx_new_image(mlx, numbers.x_max, numbers.y_max);
	imgage.addr = mlx_get_data_addr(imgage.img, &imgage.bits_per_pixel,
			&imgage.line_length, &imgage.endian);
	set = 'j';
	if (set == 'm')
		mandlebrot(85, numbers, &imgage);
	else if (set == 'j')
	{
		numbers.c_real = -2;
		numbers.c_imaginary = -1;
		julia(500, &imgage, numbers);
	}
	mlx_put_image_to_window(mlx, mlx_win, imgage.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
