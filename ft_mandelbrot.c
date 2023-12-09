/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/09 12:42:14 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double x, double y)
{
	double	image[2];
	image[0] = WIDTH;
	image[1] = HEIGHT;
	double	zoom[2];
	zoom[0] = image[0] / (0.6 - (-2.1));
	zoom[1] = image[1] / (1.2 - (-1.2));

	if (x == 0)
	{
		while (x < image[0])
			x++;
	}
	if (y == 0)
	{
		while (y < image[1])
			y++;
	}
	double	c[2];
	double	z[2];
	double	tmp;
	int	i;

	c[0] = x / zoom[0] + (-2.1);
	c[1] = y / zoom[1] + (-1.2);
	z[0] = 0;
	z[1] = 0;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < 50)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
		i++;
	}
	if (i == 50)
		return (255);
	return (0);
}
