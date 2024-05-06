/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:52:15 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:10:58 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fractol !");
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->addr_img = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->lenght_line,
			&fractal->endian);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 350;
	fractal->offset_x = -2.05;
	fractal->offset_y = -1.33;
	fractal->max_iterations = 120;
}

int	close_all(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

int	free_fractal(t_fractal *fractal)
{
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}
