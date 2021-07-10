/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:11 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/10 17:36:12 by tmatias          ###   ########.fr       */
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
			+ (numbers.c_real / (numbers.y_max / (2 * zoom_factor)));
		numbers.z_imaginary = 2 * numbers.z_real * numbers.z_imaginary
			+ (numbers.c_imaginary / (numbers.y_max / (2 * zoom_factor)));
		numbers.z_real = numbers.temp;
		iterations++;
	}
	return (iterations);
}

void	mandlebrot(int	precision, t_numbers numbers, t_data *imgage,
	float zoom_factor)
{
	int	iterations;

	numbers.c_real = 0 - (numbers.x_max / 2);
	while (numbers.c_real < numbers.x_max / 2)
	{
		numbers.c_imaginary = 0 - (numbers.y_max / 2);
		while (numbers.c_imaginary < numbers.y_max / 2)
		{
			numbers.z_real = 0;
			numbers.z_imaginary = 0;
			iterations = get_mandel_iterations(precision, numbers, zoom_factor);
			if ((iterations < precision))
			{
				my_mlx_pixel_put(imgage, numbers.c_real + (numbers.x_max / 2),
					numbers.c_imaginary + (numbers.y_max / 2),
					(create_trgb(0, 7 * (iterations + 2) + 50,
							5 * (iterations + 2), 3 * (iterations + 2))));
			}
			numbers.c_imaginary++;
		}
		numbers.c_real++;
	}
}
