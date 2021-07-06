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

void	julia(int percision, t_data *imgage, t_numbers numbers)
{
	float	x;
	float	y;
	int		iterations;

	x = 0;
	iterations = 0;
	while (x < numbers.x_max)
	{
		y = 0;
		while (y < numbers.y_max)
		{
			numbers.z_real = (x - (numbers.x_max / 2)) / (numbers.y_max / 4);
			numbers.z_imaginary
				= (y - (numbers.y_max / 2)) / (numbers.y_max / 4);
			iterations = get_julia_iterations(numbers, percision);
			if (iterations < percision)
			{
				my_mlx_pixel_put(imgage, x, y,
					(0x00000000 + ((iterations + 1) * 5000)));
			}
			y++;
		}
		x++;
	}
}
