/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:00 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/24 19:18:48 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	key_hooked(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	// else if (key_code == LEFT)
	// 	fractal->offset_x -= 42 / fractal->zoom;
	// else if (key_code == RIGHT)
	// 	fractal->offset_x += 42 / fractal->zoom;
	// else if (key_code == UP)
	// 	fractal->offset_y -= 42 / fractal->zoom;
	// else if (key_code == DOWN)
	// 	fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
	 	init_fractal(fractal);
	// else if (key_code == C)
	// 	fractal->color += (255 * 255 * 255) / 100;
	// else if (key_code == J)
	// 	set_random_julia(&fractal->cx, &fractal->cx);
	// else if (key_code == M || key_code == P)
	// 	change_iterations(fractal, key_code);
	// draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hooked(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	//draw_fractal(fractal, fractal->name);
	return (0);
}

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*temp;
	int	pixel;

	color = (color * fractal->color);
	temp = fractal->addr_img;
	pixel = (y * fractal->lenght_line / 4) + x;
	temp[pixel] = color;
}
