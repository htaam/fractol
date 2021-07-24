/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:53:58 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/24 15:48:06 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_digit_minus_or_dot(char c)
{
	int	n;

	n = 0;
	while (DIGITS_AND_STUFF[n] != 0)
	{
		if (c == DIGITS_AND_STUFF[n])
			return (1);
		n++;
	}
	return (0);
}

int	is_float(char	*ptr)
{
	int	n;

	n = 0;
	while (n < ft_strlen(ptr))
	{
		if (is_digit_minus_or_dot(ptr[n]) != 1)
			return (0);
		n++;
	}
	return (1);
}

float	do_math(size_t dotpos, int signal, float result)
{
	while (dotpos--)
		result /= 10;
	if (signal == -1)
		result = result * signal;
	return (result);
}

float	ft_atol(char	*inputstr)
{
	float	result;
	size_t	len;
	size_t	dotpos;
	size_t	n;
	int		signal;

	if (is_float(inputstr) != 1)
		invalid_input();
	signal = 0;
	if (inputstr[0] == '-')
		signal = -1;
	n = signal * -1;
	dotpos = 0;
	len = ft_strlen(inputstr);
	result = 0.0;
	while (n < len)
	{
		if (inputstr[n] == '.')
			dotpos = len - n - 1;
		else
			result = result * 10 + (inputstr[n] - '0');
		n++;
	}
	return (do_math(dotpos, signal, result));
}
