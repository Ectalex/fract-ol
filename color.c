/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:52:41 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/10 19:15:23 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_test_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_color(int i, t_mlx *mlx)
{
	if (mlx->color == 0)
	{
		if (i == mlx->iter)
			return(ft_test_color(0, 0, 0, 255));
		return(ft_test_color(3 * i, 1 * i, 10 * i, 255));
	}
	else if (mlx->color == 1)
	{
		if (i == mlx->iter)
			return(ft_test_color(0, 0, 0, 255));
		return (ft_test_color(10 * i, 1 * i, 3 * i, 255));
	}
	else if (mlx->color == 2)
	{
	if (i == mlx->iter)
			return(ft_test_color(0, 0, 0, 255));
		return (ft_test_color(3 * i, 10 * i, 1 * i, 255));
	}
	else if (mlx->color == 3)
	{
		if (i == mlx->iter)
			return(ft_test_color(255, 255, 255, 255));
		return (ft_test_color(15 * i % 67, 15 * i % 67, 15 * i % 67, 255));
	}
	return (1);
}
