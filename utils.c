/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:00 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/02 16:51:06 by gabarnou         ###   ########.fr       */
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

double ft_atod(char *str)
{
	double result = 0.0;
	int i = 0;
	int sign = 1;
	int decimal = 0;
	double decimal_place = 1.0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10.0 + (str[i] - '0');
			decimal++;
			i++;
		}
		while (decimal > 0)
		{
			decimal_place *= 10.0;
			decimal--;
		}
		result /= decimal_place;
	}

	return result * sign;
}
/*

index pour
aller a la fin ave un *tmp
reculer jusqu'au "."
envoyer a atoi
remplacer "." pa "/0"
reculer jusqu'au 

*/
