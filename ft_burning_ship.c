/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2024/06/06 17:48:35 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burn_ship(double x, double y, t_mlx *mlx)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;

	c[0] = (x / WIDTH * 4 - 2.25 - (mlx->fract.x1 / 2))
		*mlx->fract.zoom - mlx->fract.x1;
	c[1] = (y / HEIGHT * 4 - 2.25 - (mlx->fract.y1 / 2))
		* mlx->fract.zoom - mlx->fract.y1;
	z[0] = mlx->fract.x2;
	z[1] = mlx->fract.y2;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < mlx->fract.iter)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * fabs(z[1] * tmp) + c[1];
		i++;
	}
	mlx_put_pixel(mlx->image, x, y, ft_color(i, mlx));
}
