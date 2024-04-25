/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:00 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/25 16:59:49 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hooked(int key_code, t_fractal *fractal)
{
	if (key_code == XK_Escape )
		exit(1);
	else if (key_code == XK_Left)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == XK_Right)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == XK_Up)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == XK_Down)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == XK_r)
	 	init_fractal(fractal);
	else if (key_code == XK_c)
		fractal->color += (255 * 255 * 255) / 100;
	// else if (key_code == J)
	// 	set_random_julia(&fractal->cx, &fractal->cx);
	//else if (key_code == XK_m || key_code == XK_p)
	//	change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hooked(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
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
