/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:52:41 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/10 15:43:35 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_test_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_color(int i)
{
	if (i == 50)
		return(ft_test_color(0, 0, 0, 255));
	return(ft_test_color(3 * i, 1 * i, 10 * i, 255));
}
