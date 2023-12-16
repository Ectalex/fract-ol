/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:58 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/16 10:37:24 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init(t_mlx *mlx)
{
	mlx->win = NULL;
	mlx->image = NULL;
	mlx->fract.zoom = 1;
	mlx->fract.x1 = 0;
	mlx->fract.y1 = 0;
	mlx->fract.zoom_change = 0.1;
	mlx->fract.color = 3;
	mlx->fract.iter = 50;
	mlx->win = mlx_init(WIDTH, HEIGHT, "TEST", true);
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
			mlx->fract.type = 0;
		else if (!ft_strncmp(argv[1], "j", 2))
			mlx->fract.type = 1;
		else if (!ft_strncmp(argv[1], "b", 2))
			mlx->fract.type = 2;
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
