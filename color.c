/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:52:41 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/09 14:48:39 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_testcolor(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_color(int n)
{
	int	color;

	if (n == 0)
		color = ft_testcolor(0, 0, 0, 255);
	if (n == 1)
		color = ft_testcolor(225, 225, 225, 255);
	if (n == 2)
		color = ft_testcolor(30, 30, 30, 255);
	return (color);
}
