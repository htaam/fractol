/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:20:30 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/21 17:04:01 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_vars *vars)
{
	vars->zoom = vars->zoom / 1.5;
	printf("zoom = %f\n", vars->zoom);
	if (vars->input.set_type == 1)
		mandlebrot(vars->numbers.percision, vars->numbers, &vars->image, .5);
	else if (vars->input.set_type == 2)
		julia(vars->numbers.percision, &vars->image, vars->numbers, vars->zoom);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}

void	zoom_out(t_vars *vars)
{
	vars->zoom = vars->zoom * 1.5;
	printf("zoom = %f\n", vars->zoom);
	if (vars->input.set_type == 1)
		mandlebrot(vars->numbers.percision, vars->numbers, &vars->image, .5);
	else if (vars->input.set_type == 2)
		julia(vars->numbers.percision, &vars->image, vars->numbers, vars->zoom);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}
