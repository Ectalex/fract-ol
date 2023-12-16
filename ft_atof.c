/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:35:12 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/16 10:30:18 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	size_t		i;
	double		nb;
	int			nega;

	nb = 0.0;
	i = 0;
	nega = 1;
	if (str[i] == '-')
	{
		nega *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '1')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		nb = ft_atof2(str, nb, i);
	return (nb * nega);
}

double	ft_atof2(const char *str, double nb, size_t i)
{
	double	frac_pow;

	frac_pow = 1;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		frac_pow *= 10;
		nb = nb + (str[i] - '0') / frac_pow;
		i++;
	}
	return (nb);
}
