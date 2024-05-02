/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:00 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/02 17:05:45 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == XK_m)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == XK_p)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

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
	else if (key_code == XK_m || key_code == XK_p)
		change_iterations(fractal, key_code);
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

double	ft_atod(char *str)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || 32 == *str)
		++str;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			sign = -sign;
	while (*str != '.' && *str)
		integer_part = (integer_part * 10) + (*str++ - 48);
	if ('.' == *str)
		++str;
	while (*str)
	{
		pow /= 10;
		fractional_part = fractional_part + (*str++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
