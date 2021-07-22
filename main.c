/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:57:56 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/22 18:10:48 by tmatias          ###   ########.fr       */
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

int	key_hook(int keycode, t_vars *vars)
{
	if (vars)
		;
	if (keycode == 53)
		exit (0);
	if (keycode == 69)
		zoom_in(vars);
	if (keycode == 78)
		zoom_out(vars);
	return (keycode);
}

int	mouse_hook(int mouse_code, t_vars *vars)
{
	if (vars)
		;
	if (mouse_code == 3)
		vars->zoom = vars->zoom * 2;
	if (mouse_code == 5)
		vars->zoom = vars->zoom / 2;
	printf("mouse code = %d\n", mouse_code);
	return (mouse_code);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc < 2)
		invalid_input();
	vars.zoom = 1;
	vars.numbers.x_max = 1920;
	vars.numbers.y_max = 1080;
	handdle_inputs(&vars.input, &vars.numbers, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.numbers.x_max, vars.numbers.y_max, "");
	vars.image.img = mlx_new_image(vars.mlx, vars.numbers.x_max, vars.numbers.y_max);
	vars.image.addr = mlx_get_data_addr(vars.image.img, &vars.image.bits_per_pixel,
			&vars.image.line_length, &vars.image.endian);
	if (vars.input.set_type == 1)
		mandlebrot(vars.numbers.percision, vars.numbers, &vars.image, vars.zoom);
	else if (vars.input.set_type == 2)
		julia(vars.numbers.percision, &vars.image, vars.numbers, vars.zoom);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
