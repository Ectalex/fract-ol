/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:58 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/06 10:29:17 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#define BPP sizeof(int)

static mlx_image_t	*g_img;

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_B))
		memset(g_img->pixels, 255, g_img->width * g_img->height * BPP);
	if (mlx_is_key_down(mlx, MLX_KEY_C))
		memset(g_img->pixels, 125, g_img->width * g_img->height * BPP);
	if (mlx_is_key_down(mlx, MLX_KEY_N))
		memset(g_img->pixels, 0, g_img->width * g_img->height * BPP);


}

void	ft_color(mlx_t *mlx)
{
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(g_img->pixels, 255, g_img->width * g_img->height * BPP);
	mlx_image_to_window(mlx, g_img, 0, 0);
}

int main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "TEST", true);
	ft_hook(mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	ft_color(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
