/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:28:29 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:13:56 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *str)
{
	if (ft_strncmp(str, "mandel", 7) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(str, "julia", 6) == 0)
		draw_julia(fractal);
	else if (ft_strncmp(str, "ship", 5) == 0)
		draw_ship(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img, 0, 0);
	return (0);
}

void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calcul_mandel(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calcul_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	draw_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calcul_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}
