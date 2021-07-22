/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:25 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/22 17:10:48 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_julia_iterations(t_numbers numbers, int percision)
{
	int	iterations;

	iterations = 0;
	while (pow(numbers.z_real, 2) + pow(numbers.z_imaginary, 2) < 4
		&& iterations < percision)
	{
		numbers.temp
			= pow(numbers.z_real, 2) - pow(numbers.z_imaginary, 2)
			+ (numbers.c_real);
		numbers.z_imaginary
			= 2 * (numbers.z_real) * (numbers.z_imaginary)
			+ (numbers.c_imaginary);
		numbers.z_real = numbers.temp;
		iterations++;
	}
	return (iterations);
}

void	julia(int percision, t_data *imgage, t_numbers numbers,
	float zoom_factor)
{
	float	x;
	float	y;
	int		iterations;

	x = 0;
	while (x < numbers.x_max)
	{
		y = 0;
		while (y < numbers.y_max)
		{
			numbers.z_real = (x - (numbers.x_max / 2))
				/ (numbers.y_max / (2 / zoom_factor));
			numbers.z_imaginary = (y - (numbers.y_max / 2))
				/ (numbers.y_max / (2 / zoom_factor));
			iterations = get_julia_iterations(numbers, percision);
			if (iterations < percision)
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
