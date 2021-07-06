#include "fractol.h"

void julia(float cx, float cy, t_data *imgage, t_numbers numbers)
{
	float	x;
	float	y;

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
}