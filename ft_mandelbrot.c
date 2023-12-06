/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/06 17:37:47 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
static void	ft_mandelbrot_iter(double z[2], double z2[2], double c[2])
{
	z[1] = 2 * z[0] * z[1] + c[1];
	z[0] = z2[0] - z2[1] + c[0];
	z2[0] = z[0] * z[0];
	z2[1] = z[1] * z[1];
}
*/
int	ft_mandelbrot(double x, double y, t_mlx *mlx)
{
	/*
	double	z[2];
	double	z2[2];
	double	c[2];
	double	i;

	i = 0.0L;
	z2[0] = z[0] * z[0];
	z2[1] = z[1] * z[1];
	while (i < 21.0L && z2[0] + z2[1] < 4)
	{
		ft_mandelbrot_iter(z, z2, c);
		i++;
	}
	*/
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < 21.0L)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + y;
		zr = zr * zr - zi * zi + x;
		zi = tmp;
		n++;
	}
	return (tmp);
}
