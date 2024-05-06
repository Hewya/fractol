/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:28:34 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:17:04 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcul_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	i = 0;
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		color_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}
