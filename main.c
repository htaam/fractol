/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:57:56 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/07 18:07:11 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	invalid_input(char **argv)
{
	char	**a;

	a = argv;
	printf("\nInvalid input\n\nHere is a list of valid inputs:\n");
	printf("\tMandlebrot #persision(optional)\n");
	printf("\tJulia #real_C #imaginary_C #persision(optional)\n\n");
	printf("\nIf no persision is inputed it will be assumed 42*2\n");
	printf("If percision is above 255 the value of 255 is assumed\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_data		imgage;
	t_numbers	numbers;
	char		set;

	if (argc < 2)
		invalid_input(argv);
	numbers.x_max = 1920;
	numbers.y_max = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, numbers.x_max, numbers.y_max, "Fractal");
	imgage.img = mlx_new_image(mlx, numbers.x_max, numbers.y_max);
	imgage.addr = mlx_get_data_addr(imgage.img, &imgage.bits_per_pixel,
			&imgage.line_length, &imgage.endian);
	set = 'j';
	numbers.percision = 5000;
	if (numbers.percision > 254)
		numbers.percision = 254;
	if (set == 'm')
		mandlebrot(numbers.percision, numbers, &imgage);
	else if (set == 'j')
	{
		numbers.c_real = .42;
		numbers.c_imaginary = .42;
		julia(numbers.percision, &imgage, numbers);
	}
	mlx_put_image_to_window(mlx, mlx_win, imgage.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
