/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/16 10:39:57 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_burn_ship(double x, double y, t_mlx *mlx)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;

	c[0] = (x / WIDTH * 3 - 2 - mlx->fract.x1) * mlx->fract.zoom;
	c[1] = (y / HEIGHT * 3 - 1.5 - mlx->fract.y1) * mlx->fract.zoom;
	z[0] = -2.5 + mlx->fract.x2;
	z[1] = 1 + mlx->fract.y2;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < mlx->fract.iter)
	{
		tmp = z[0] * z[0] - z[1] * z[1] + x;
		z[1] = 2 * z[1] * z[1] + y;
		z[0] = tmp;
		i++;
	}
	return (i);
}
