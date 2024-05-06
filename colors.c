/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:20:46 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:14:04 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*temp;
	int	pixel;

	color = (color * fractal->color);
	temp = fractal->addr_img;
	pixel = (y * fractal->lenght_line / 4) + x;
	temp[pixel] = color;
}
