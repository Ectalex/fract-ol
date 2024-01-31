/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:58 by albriffa          #+#    #+#             */
/*   Updated: 2024/01/31 14:49:45 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init(t_mlx *mlx)
{
	mlx->win = NULL;
	mlx->image = NULL;
	mlx->fract.zoom = 1;
	mlx->fract.mx = 0.0;
	mlx->fract.my = 0.0;
	mlx->fract.x1 = 0;
	mlx->fract.y1 = 0;
	mlx->fract.x3 = 0;
	mlx->fract.y3 = 0;
	mlx->fract.zoom_change = 0.1;
	mlx->fract.color = 3;
	mlx->fract.iter = 22;
	mlx->win = mlx_init(WIDTH, HEIGHT, mlx->fract.type, true);
	mlx->image = mlx_new_image(mlx->win, WIDTH, HEIGHT);
	mlx_image_to_window(mlx->win, mlx->image, 0, 0);
}

int	ft_fractol(int argc, char **argv, t_mlx *mlx)
{
	if (1 < argc)
	{
		if (argv[2] && argv[3] && !argv[4])
		{
			mlx->fract.x2 = ft_atof(argv[2]);
			mlx->fract.y2 = ft_atof(argv[3]);
		}
		else
		{
			mlx->fract.x2 = 0.0;
			mlx->fract.y2 = 0.0;
		}
		if (!ft_strncmp(argv[1], "m", 2))
		{
			mlx->fract.choice = 0;
			mlx->fract.type = "Mandelbrot";
		}
		else if (!ft_strncmp(argv[1], "j", 2))
		{
			mlx->fract.choice = 1;
			mlx->fract.type = "Julia";
		}
		else if (!ft_strncmp(argv[1], "b", 2))
		{
			mlx->fract.choice = 2;
			mlx->fract.type = "Burning Ship";
		}
		else
			return (0);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

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
		write(1, ERROR, 42);
	return (EXIT_SUCCESS);
}
