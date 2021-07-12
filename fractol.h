/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:57:38 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/12 16:33:07 by tmatias          ###   ########.fr       */
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

# ifndef DIGITS_AND_STUFF
#  define DIGITS_AND_STUFF "-.0123456789"
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

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
	float	x;
	float	y;
	float	temp;
	int		x_max;
	int		y_max;
	int		order;
	int		percision;
}			t_numbers;

typedef struct s_inputs
{
	int		set_type;
}				t_inputs;

void			mandlebrot(int	precision, t_numbers numbers, t_data *imgage,
					float zoom_factor);
void			julia(int percision, t_data *imgage, t_numbers numbers,
					float zoom_factor);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
int				ft_strncmp(const char *c1, const char *c2, size_t n);
int				ft_strlen(char *str);
void			invalid_input(void);
long long int	ft_atoi_with_error(const char *str);
float			ft_atol(char	*input_str);
int				is_float(char	*ptr);

#endif