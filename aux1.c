/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:13 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/10 15:47:41 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_distance(int x1, int y1, int x2, int y2)
{
	int	c;

	c = sqrt(pow((x1 - x2), 2) + (pow((y1 - y2), 2)));
	return (c);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_strncmp(const char *c1, const char *c2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)c1;
	s2 = (char *)c2;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2++)
		{
			return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
		}
		if (*s1++ == 0)
			break ;
		n--;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	counter;

	if (!*str)
		return (0);
	counter = 0;
	while (!(*str == 0))
	{
		counter++;
		str++;
	}
	return (counter);
}
