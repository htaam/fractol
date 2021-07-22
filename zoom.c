/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:20:30 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/22 18:00:43 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_vars *vars)
{
	t_data	img;
	float	zoom;

	img.img = mlx_new_image(vars->mlx, vars->numbers.x_max,
			vars->numbers.y_max);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	zoom = vars->zoom * 2;
	vars->zoom = zoom;
	if (vars->input.set_type == 1)
		mandlebrot(vars->numbers.percision, vars->numbers, &img, zoom);
	else if (vars->input.set_type == 2)
		julia(vars->numbers.percision, &img, vars->numbers, vars->zoom);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	free(img.img);
}

void	zoom_out(t_vars *vars)
{
	t_data	img;
	float	zoom;

	img.img = mlx_new_image(vars->mlx, vars->numbers.x_max,
			vars->numbers.y_max);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	zoom = vars->zoom / 2;
	vars->zoom = zoom;
	if (vars->input.set_type == 1)
		mandlebrot(vars->numbers.percision, vars->numbers, &img, zoom);
	else if (vars->input.set_type == 2)
		julia(vars->numbers.percision, &img, vars->numbers, vars->zoom);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	free(img.img);
}
