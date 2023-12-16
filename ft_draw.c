/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:58 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/16 09:54:36 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	ft_pixel(mlx->image, mlx);
}

void	ft_pixel(mlx_image_t *image, t_mlx *mlx)
{
	float	x;
	float	y;

	x = 0;
	while (x < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			if (mlx->fract.type == 0)
				mlx_put_pixel(image, x, y,
					ft_color(ft_mandelbrot(x, y, mlx), mlx));
			if (mlx->fract.type == 1)
				mlx_put_pixel(image, x, y,
					ft_color(ft_julia(x, y, mlx), mlx));
			if (mlx->fract.type == 2)
				mlx_put_pixel(image, x, y,
					ft_color(ft_burn_ship(x, y, mlx), mlx));
			y++;
		}
		x++;
	}
}
