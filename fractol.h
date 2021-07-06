/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:57:38 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/06 17:06:38 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_numbers
{
	float	z_real;
	float	z_imaginary;
	float	c_real;
	float	c_imaginary;
	float	temp;
	int		x_max;
	int		y_max;
}			t_numbers;

void	mandlebrot(int	precision, t_numbers numbers, t_data *imgage);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif