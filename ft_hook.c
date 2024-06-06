/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:58 by albriffa          #+#    #+#             */
/*   Updated: 2024/06/06 17:08:16 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_key(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	my_key2(mlx);
	if (mlx_is_key_down(mlx->win, MLX_KEY_A))
		mlx->fract.x2 += 0.01;
	if (mlx_is_key_down(mlx->win, MLX_KEY_D))
		mlx->fract.x2 -= 0.01;
	if (mlx_is_key_down(mlx->win, MLX_KEY_W))
		mlx->fract.y2 += 0.01;
	if (mlx_is_key_down(mlx->win, MLX_KEY_S))
		mlx->fract.y2 -= 0.01;
	if (mlx_is_key_down(mlx->win, MLX_KEY_MINUS))
		mlx->fract.iter -= 2;
	if (mlx_is_key_down(mlx->win, MLX_KEY_EQUAL))
		mlx->fract.iter += 2;
}

#include <stdio.h>

void	my_key2(t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->win, MLX_KEY_ESCAPE))
		mlx_close_window(mlx->win);
	if (mlx_is_key_down(mlx->win, MLX_KEY_Z))
		mlx->fract.color = 0;
	if (mlx_is_key_down(mlx->win, MLX_KEY_X))
		mlx->fract.color = 1;
	if (mlx_is_key_down(mlx->win, MLX_KEY_C))
		mlx->fract.color = 2;
	if (mlx_is_key_down(mlx->win, MLX_KEY_O))
		mlx->fract.color = 3;
	if (mlx_is_key_down(mlx->win, MLX_KEY_LEFT))
		mlx->fract.x1 += mlx->fract.zoom_change;
	if (mlx_is_key_down(mlx->win, MLX_KEY_RIGHT))
		mlx->fract.x1 -= mlx->fract.zoom_change;
	if (mlx_is_key_down(mlx->win, MLX_KEY_UP))
		mlx->fract.y1 += mlx->fract.zoom_change;
	if (mlx_is_key_down(mlx->win, MLX_KEY_DOWN))
		mlx->fract.y1 -= mlx->fract.zoom_change;
}

#include <stdio.h>

void	my_scroll(double xdelta, double ydelta, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	(void)xdelta;
	if (ydelta < 0)
	{
		mlx->fract.zoom_change *= 1.1;
		mlx->fract.zoom += mlx->fract.zoom_change;
	}
	if (ydelta > 0)
	{
		mlx->fract.zoom_change /= 1.1;
		mlx->fract.zoom -= mlx->fract.zoom_change;
	}
}
