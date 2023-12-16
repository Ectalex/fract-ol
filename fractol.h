/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:13:48 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/16 10:43:59 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 900
# define HEIGHT 900

# define ERROR "m = Mandelbrot\nj = Julia\nb = Burning Ship\n"

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx/mlx42.h"

typedef struct s_fractol
{
	double	zoom;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_change;
	double	iter;
	int		color;
	int		type;
}	t_fractol;

typedef struct s_mlx
{
	mlx_t		*win;
	mlx_image_t	*image;
	t_fractol	fract;
}	t_mlx;

void	ft_draw(void *param);
void	ft_pixel(mlx_image_t *image, t_mlx *mlx);
void	my_key(void *param);
void	my_key2(t_mlx *mlx);
void	my_scroll(double xdelta, double ydelta, void *param);
double	ft_atof(const char *str);
double	ft_atof2(const char *str, double nb, size_t i);
int		ft_mandelbrot(double x, double y, t_mlx *mlx);
int		ft_julia(double x, double y, t_mlx *mlx);
int		ft_burn_ship(double x, double y, t_mlx *mlx);
int		ft_color(int n, t_mlx *mlx);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
