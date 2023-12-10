/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/10 19:45:06 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_burn_ship(double x, double y, t_mlx *mlx)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int	i;

	c[0] = (x / WIDTH * 3 - 2 - mlx->x1) * mlx->zoom;
	c[1] = (y / HEIGHT * 3 - 1.5 - mlx->y1) * mlx->zoom;
	z[0] = -2.5 + mlx->x2;
	z[1] = 1 + mlx->y2;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < mlx->iter)
	{
		tmp = z[0] * z[0] - z[1] * z[1] + x;
		z[1] = 2 * z[1] * z[1] + y;
		z[0] = tmp;
		i++;
	}
	return (i);
}
