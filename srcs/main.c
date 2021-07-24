/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:57:56 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/24 17:36:39 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	init_stuff(t_vars *vars, char *argv)
{
	vars->zoom = 1;
	vars->numbers.x_max = 1920;
	vars->numbers.y_max = 1080;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->numbers.x_max,
			vars->numbers.y_max, argv);
	vars->image.img = mlx_new_image(vars->mlx, vars->numbers.x_max,
			vars->numbers.y_max);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel,
			&vars->image.line_length, &vars->image.endian);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	void		*aux;

	aux = &vars;
	if (argc < 2)
		invalid_input();
	handdle_inputs(&vars.input, &vars.numbers, argv);
	init_stuff(&vars, argv[1]);
	if (vars.input.set_type == 1)
		mandlebrot(vars.numbers.percision, vars.numbers,
			&vars.image, vars.zoom);
	else if (vars.input.set_type == 2)
		julia(vars.numbers.percision, &vars.image, vars.numbers, vars.zoom);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, 0L, red_cross, aux);
	mlx_hook(vars.win, 2, 0L, key_hook, aux);
	mlx_loop(vars.mlx);
}
