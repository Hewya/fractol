/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:28:52 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/30 16:48:10 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.20;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / zoom_level));
				/*
					x					= position actuelle du curseur
					fractal->zoom		= niveau de zoom
					fractal-> offset_x	= position horizontale actuelle du coin sup gauche (HERE ?????????)

					(x / fractal->zoom + fractal->offset_x)
							= calcule position curseur dans l'image en prenant en compte la position du curseur
							par rapport au coin sup gauche et le niveau de zoom

					(x / (fractal->zoom / zoom_level))
							= calcule la nouvelle position du curseur dans l'image apres le zoom

					(x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / zoom_level))
							= la soustration permet de deplacer l'image dans la direction opposee au curseur
				
				*/
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}
