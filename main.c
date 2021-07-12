/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:57:56 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/12 17:03:13 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	invalid_input(void)
{
	printf("\nInvalid input\n\nHere is a list of valid inputs:\n");
	printf("\tMandlebrot #persision(optional)\n");
	printf("\tJulia #real_C #imaginary_C #persision(optional)\n\n");
	printf("\nIf no persision is inputed it will be assumed 254\n");
	printf("If percision value is too high it will take ");
	printf("a long time to calculate\n");
	printf("Any values after the ones asked for will be ignored\n\n");
	exit (0);
}

void	handdle_inputs(t_inputs *inputs, t_numbers *numbers, char	**argv)
{
	if (!ft_strncmp(argv[1], "Mandlebrot", 10000))
		inputs->set_type = 1;
	else if (!ft_strncmp(argv[1], "Julia", 10000))
		inputs->set_type = 2;
	else
		invalid_input();
	if (inputs->set_type == 1)
	{
		if (argv[2])
		{
			numbers->percision = ft_atoi_with_error(argv[2]);
			if (numbers->percision < 1)
				invalid_input();
		}
		else
			numbers->percision = 255;
	}
	else if (inputs->set_type == 2 && (argv[2] && argv[3]))
	{
		numbers->c_real = ft_atol(argv[2]);
		numbers->c_imaginary = ft_atol(argv[3]);
		if (argv[4])
		{
			numbers->percision = ft_atoi_with_error(argv[4]);
			if (numbers->percision < 1)
				invalid_input();
		}
		else
			numbers->percision = 255;
	}
	else
		invalid_input();
}

int	key_hook(int keycode, t_vars *vars)
{
	if (vars)
		;
	if (keycode == 53)
		exit (0);
	return (keycode);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_data		imgage;
	t_numbers	numbers;
	t_inputs	inputs;

	if (argc < 2)
		invalid_input();
	numbers.x_max = 1920;
	numbers.y_max = 1080;
	handdle_inputs(&inputs, &numbers, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, numbers.x_max, numbers.y_max, "Fractal");
	imgage.img = mlx_new_image(vars.mlx, numbers.x_max, numbers.y_max);
	imgage.addr = mlx_get_data_addr(imgage.img, &imgage.bits_per_pixel,
			&imgage.line_length, &imgage.endian);
	numbers.order = 2;
	if (inputs.set_type == 1)
		mandlebrot(numbers.percision, numbers, &imgage, 1.5);
	else if (inputs.set_type == 2)
		julia(numbers.percision, &imgage, numbers, 1.1);
	mlx_put_image_to_window(vars.mlx, vars.win, imgage.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
