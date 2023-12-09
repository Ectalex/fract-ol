/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/09 12:10:08 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double x, double y)
{
/*	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;
	int	zoom = 100;
	double	image_x = (x2 - x1) * zoom;
	double	image_y = (y2 - y1) * zoom;

	if (x == 0)
	{
		while (x < image_x)
			x++;
	}
	if (y == 0)
	{
		while (y < image_y)
			y++;
	}*/
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int	i;

	c_r = x /*/ zoom + x1*/;
	c_i = y /*/ zoom + y1*/;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < 50)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	return (i != 49);
}
