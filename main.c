/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:57:56 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/06 17:05:48 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_distance(int x1, int y1, int x2, int y2)
{
	int	c;

	c = sqrt(pow((x1 - x2), 2) + (pow((y1 - y2), 2)));
	return (c);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		imgage;
	t_numbers	numbers;

	numbers.x_max = 1920;
	numbers.y_max = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, numbers.x_max, numbers.y_max, "Hello world!");
	imgage.img = mlx_new_image(mlx, numbers.x_max, numbers.y_max);
	imgage.addr = mlx_get_data_addr(imgage.img, &imgage.bits_per_pixel,
			&imgage.line_length, &imgage.endian);
	mandlebrot(85, numbers, &imgage);
	mlx_put_image_to_window(mlx, mlx_win, imgage.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

/*int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		imgage;
	t_numbers	numbers;
	int			iteration;
	double			x;
	double			y;

	numbers.x_max = 1920;
	numbers.y_max = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, numbers.x_max, numbers.y_max, "Hello world!");
	imgage.img = mlx_new_image(mlx, numbers.x_max, numbers.y_max);
	imgage.addr = mlx_get_data_addr(imgage.img, &imgage.bits_per_pixel,
			&imgage.line_length, &imgage.endian);
	x = 0;
	numbers.c_real = -1;
	numbers.c_imaginary = 0;
	while (x < numbers.x_max)
	{
		y = 0;
		while (y < numbers.y_max)
		{
			iteration = 0;
			numbers.z_real = (x - (numbers.x_max / 2)) / (numbers.y_max / 4);
			numbers.z_imaginary = (y - (numbers.y_max / 2)) / (numbers.y_max / 4);
			while (pow(numbers.z_real, 2) + pow(numbers.z_imaginary, 2) < 4
				&& iteration < 500)
			{
				numbers.temp = pow(numbers.z_real, 2) - pow(numbers.z_imaginary, 2)
					+ (numbers.c_real);
				numbers.z_imaginary = 2 * (numbers.z_real) * (numbers.z_imaginary)
					+ (numbers.c_imaginary);
				numbers.z_real = numbers.temp;
				iteration++;
			}
			if (iteration < 500)
			{
				my_mlx_pixel_put(&imgage, x, y, (0x00000000 + ((iteration + 1) * 5000)));
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, imgage.img, 0, 0);
	mlx_loop(mlx);
}*/
