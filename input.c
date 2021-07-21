/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:10:44 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/20 17:16:14 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandle_inputs(t_numbers *numbers, char	**argv)
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

void	julia_inputs(t_numbers *numbers, char	**argv)
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

void	handdle_inputs(t_inputs *inputs, t_numbers *numbers, char	**argv)
{
	if (!ft_strncmp(argv[1], "Mandlebrot", 10000))
		inputs->set_type = 1;
	else if (!ft_strncmp(argv[1], "Julia", 10000))
		inputs->set_type = 2;
	else
		invalid_input();
	if (inputs->set_type == 1)
		mandle_inputs(numbers, argv);
	else if (inputs->set_type == 2 && (argv[2] && argv[3]))
		julia_inputs(numbers, argv);
	else
		invalid_input();
}
