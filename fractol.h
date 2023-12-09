/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:13:48 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/09 11:50:21 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 900
# define HEIGHT 900

# define FRACT_COUNT 4

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include "minilibx/mlx42.h"

typedef struct s_fractol
{
	int	type;
}	t_fractol;

typedef struct s_mlx
{
	mlx_t	*win;
	mlx_image_t	*image;
	t_fractol	fract;
}	t_mlx;

void	ft_draw(void *param);
void	ft_pixel(mlx_image_t *image, t_mlx *mlx);
int	ft_mandelbrot(double x, double y);

#endif
