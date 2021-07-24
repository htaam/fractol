/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:11 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/24 15:48:15 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_mandel_iterations(int percision, t_numbers numbers, float zoom_factor)
{
	int	iterations;

	iterations = 0;
	while (pow(numbers.z_real, 2) + pow(numbers.z_imaginary, 2) < 4
		&& iterations < percision)
	{
		numbers.temp = pow(numbers.z_real, 2) - pow(numbers.z_imaginary, 2)
			+ (numbers.c_real / (numbers.y_max / (2 / zoom_factor)));
		numbers.z_imaginary = 2 * numbers.z_real * numbers.z_imaginary
			+ (numbers.c_imaginary / (numbers.y_max / (2 / zoom_factor)));
		numbers.z_real = numbers.temp;
		iterations++;
	}
	return (iterations);
}

void	mandlebrot(int	precision, t_numbers numbers, t_data *imgage,
	float zoom_factor)
{
	int		iterations;
	float	x;
	float	y;

	x = 0;
	while (x < numbers.x_max)
	{
		y = 0;
		while (y < numbers.y_max)
		{
			numbers.c_real = x - (numbers.x_max / 2);
			numbers.c_imaginary = y - (numbers.y_max / 2);
			numbers.z_real = 0;
			numbers.z_imaginary = 0;
			iterations = get_mandel_iterations(precision, numbers, zoom_factor);
			if ((iterations < precision))
			{
				my_mlx_pixel_put(imgage, x,
					y, (create_trgb(0, 2.5 * (iterations) + 50,
							2.5 * (iterations), 0.3 * (iterations + 2))));
			}
			y++;
		}
		x++;
	}
}
