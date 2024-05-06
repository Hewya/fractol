/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:02:33 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:14:53 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcul_ship(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (i < fractal->max_iterations)
	{
		temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = fabs(2. * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = fabs(temp);
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		color_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}
