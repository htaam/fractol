/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:48:36 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/24 17:36:37 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 69 || keycode == 4)
		zoom_in(vars);
	if (keycode == 78)
		zoom_out(vars);
	return (keycode);
}

int	mouse_hook(int mouse_code, int x, int y, t_vars *vars)
{
	if (x && y)
		;
	if (mouse_code == 4)
		zoom_out(vars);
	if (mouse_code == 5)
		zoom_in(vars);
	return (mouse_code);
}

int	red_cross(void)
{
	exit(0);
	return (0);
}
