/* ************************************************************************** */
///*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:58 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/10 17:03:36 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init(t_mlx *mlx)
{
	mlx->win = NULL;
	mlx->image = NULL;
	mlx->zoom = 1;
	mlx->x1 = 0;
	mlx->y1 = 0;
	mlx->x2 = 0;
	mlx->y2 = 0;
	mlx->zoom_change = 0.1;
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
			if (mlx->fract.type == 0)
				mlx_put_pixel(image, x, y, ft_color(ft_mandelbrot(x, y, mlx)));
			if (mlx->fract.type == 1)
				mlx_put_pixel(image, x, y, ft_color(ft_julia(x, y, mlx)));
			y++;
		}
		x++;
	}

}

void	my_key(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx->win, MLX_KEY_ESCAPE))
		mlx_close_window(mlx->win);
	if (mlx_is_key_down(mlx->win, MLX_KEY_LEFT))
		mlx->x1 += 0.1;
	if (mlx_is_key_down(mlx->win, MLX_KEY_RIGHT))
		mlx->x1 -= 0.1;
	if (mlx_is_key_down(mlx->win, MLX_KEY_UP))
		mlx->y1 += 0.1;
	if (mlx_is_key_down(mlx->win, MLX_KEY_DOWN))
		mlx->y1 -= 0.1;
	if (mlx_is_key_down(mlx->win, MLX_KEY_A))
		mlx->x2 += 0.01;
	if (mlx_is_key_down(mlx->win, MLX_KEY_D))
		mlx->x2 -= 0.01;
	if (mlx_is_key_down(mlx->win, MLX_KEY_W))
		mlx->y2 += 0.01;
	if (mlx_is_key_down(mlx->win, MLX_KEY_S))
		mlx->y2 -= 0.01;
}

void	my_scroll(double xdelta, double ydelta, void *param)
{
	t_mlx	*mlx;

	mlx = param;
        if (mlx->zoom <= 0.2)
		mlx->zoom_change = 0.01;
	else if (mlx->zoom > 0.2)
		mlx->zoom_change = 0.1;
	if (ydelta < 0)
		mlx->zoom += mlx->zoom_change;
	if (ydelta > 0)
		mlx->zoom -= mlx->zoom_change;
}

int	ft_fractol(int argc, char **argv, t_mlx *mlx)
{
	if (1 < argc)
	{
		if (!ft_strncmp(argv[1], "m", 2))
			mlx->fract.type = 0;
		else if (!ft_strncmp(argv[1], "j", 2))
			mlx->fract.type = 1;
		else
			return (0);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx = {};

	if (ft_fractol(argc, argv, &mlx) == 1)
	{
		ft_init(&mlx);
		mlx_loop_hook(mlx.win, &my_key, &mlx);
		mlx_scroll_hook(mlx.win, &my_scroll, &mlx);
		mlx_loop_hook(mlx.win, &ft_draw, &mlx);
		mlx_loop(mlx.win);
		mlx_terminate(mlx.win);
	}
	else
		write(1, "m = Mandelbrot\nj = Julia\n", 26);
	return (EXIT_SUCCESS);
}
