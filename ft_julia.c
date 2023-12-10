/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:21 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/10 17:13:22 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(double x, double y, t_mlx *mlx)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int	i;

	z[0] = (x / WIDTH * 3 - 1.5 - mlx->x1) * mlx->zoom;
	z[1] = (y / HEIGHT * 3 - 1.5 - mlx->y1) * mlx->zoom;
	c[0] = 0.3 + mlx->x2;
	c[1] = 0.5 + mlx->y2;
	i = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < 50)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
		i++;
	}
	return (i);
}
