/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:58 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/09 12:45:14 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init(t_mlx *mlx)
{
	mlx->win = NULL;
	mlx->image = NULL;
	mlx->win = mlx_init(WIDTH, HEIGHT, "TEST", true);
	mlx->image = mlx_new_image(mlx->win, WIDTH, HEIGHT);
	mlx_image_to_window(mlx->win, mlx->image, 0, 0);
}

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
			mlx_put_pixel(image, x, y, ft_mandelbrot(x, y));
			y++;
		}
		x++;
	}

}

int	main(void)
{
	t_mlx	mlx = {};

	ft_init(&mlx);
	mlx_loop_hook(mlx.win, &ft_draw, &mlx);
	mlx_loop(mlx.win);
	mlx_terminate(mlx.win);
	return (EXIT_SUCCESS);
}
