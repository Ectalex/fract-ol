/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/10 19:17:37 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double x, double y, t_mlx *mlx)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int	i;

	c[0] = (x / WIDTH * 3 - 2 - mlx->x1) * mlx->zoom;
	c[1] = (y / HEIGHT * 3 - 1.5 - mlx->y1) * mlx->zoom;
	z[0] = mlx->x2;
	z[1] = mlx->y2;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < mlx->iter)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
		i++;
	}
	return (i);
}
