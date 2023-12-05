/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:52:03 by albriffa          #+#    #+#             */
/*   Updated: 2023/12/05 10:57:55 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

int main(void)
{
    void	*mlx_ptr;

    mlx_ptr = mlx_init();
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
