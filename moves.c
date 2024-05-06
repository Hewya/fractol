/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:28:52 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:08:51 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.20;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x)
			- (x / (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y)
			- (y / (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x)
			- (x / (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y)
			- (y / (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}
