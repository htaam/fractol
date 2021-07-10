/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:48:24 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/10 17:13:13 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

static int	ft_atoi_aux (char *ptr, long long int signal, int a)
{
	long long	result;

	result = 0;
	while ((ptr[a]))
	{
		if (!ft_isdigit(ptr[a]))
			invalid_input();
		result = result * 10 + (ptr[a] - 48);
		a++;
	}
	if (signal * result < -2147483648 || signal * result > 2147483647)
		invalid_input();
	return (result * signal);
}

long long int	ft_atoi_with_error(const char *str)
{
	long long int	signal;
	char			*ptr;
	int				a;

	a = 0;
	signal = 1;
	ptr = (char *)str;
	while ((ptr[a] == 32 || ptr[a] == '\t' || ptr[a] == '\v'
			|| ptr[a] == '\f' || ptr[a] == '\r' || ptr[a] == '\n')
		&& ptr[a] != 0)
		a++;
	if (!(ptr[a]))
		invalid_input();
	if (ptr[a] == '-' || ptr[a] == '+')
	{
		if (ptr[a] == '-')
			signal = -1;
		a++;
	}
	return (ft_atoi_aux(ptr, signal, a));
}
