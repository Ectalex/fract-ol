/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:52:41 by albriffa          #+#    #+#             */
/*   Updated: 2024/06/06 17:51:33 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_test_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_color(int i, t_mlx *mlx)
{
	if (mlx->fract.color == 1)
	{
		if (i >= mlx->fract.iter)
			return (ft_test_color(0, 0, 0, 255));
		return (ft_test_color(10 * i, 1 * i, 3 * i, 255));
	}
	else if (mlx->fract.color == 2)
	{
		if (i >= mlx->fract.iter)
			return (ft_test_color(0, 0, 0, 255));
		return (ft_test_color(30 * (i % 32) - i, 18 * (i % 92) - i, 10
				* (i % 52) - i, 255));
	}
	else if (mlx->fract.color == 3)
	{
		if (i >= mlx->fract.iter)
			return (ft_test_color(255, 255, 255, 255));
		return (ft_test_color(15 * i % 67, 15 * i % 67, 15 * i % 67, 255));
	}
	return (0);
}
