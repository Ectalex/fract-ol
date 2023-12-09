/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/09 15:56:41 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double x, double y, t_mlx *mlx)
{
	double	zoom[2];
	zoom[0] = WIDTH / (0.6 - (-2.1));
	zoom[1] = HEIGHT / (1.2 - (-1.2));

	if (x == 0)
	{
		while (x < WIDTH)
			x++;
	}
	if (y == 0)
	{
		while (y < HEIGHT)
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
		return (1);
	return (0);
}
