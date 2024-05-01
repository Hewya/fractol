/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:20:46 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/01 11:39:48 by gabarnou         ###   ########.fr       */
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

/*void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int *temp;
	int pixel;

	// Calcul de la distance entre le pixel et la fractale (à adapter selon votre algorithme)
	double distance = calculer_distance_fractale(x, y);

	// Calcul de l'opacité en fonction de la distance
	double alpha = opacite(distance);

	// Ajustement de l'opacité de la couleur existante
	int alpha_value = (int)(alpha * 255); // Convertir en valeur sur 8 bits (0-255)
	color = (color & 0x00FFFFFF) | (alpha_value << 24); // Déplacer alpha sur les 8 bits les plus significatifs

	temp = fractal->addr_img;
	pixel = (y * fractal->lenght_line / 4) + x;
	temp[pixel] = color;
}

// Fonction pour calculer l'opacité en fonction de la distance (à adapter selon vos besoins)
double	opacite(double distance)
{
	double distance_maximale = 100.0; // Ajuster selon vos besoins
	double coefficient = 0.5; // Ajuster selon vos besoins

	// Calcul de l'opacité en fonction de la distance
	double opacity = pow((1.0 - distance / distance_maximale), coefficient);

	return opacity;
}

// Fonction pour calculer la distance euclidienne entre deux points
double distance_entre_points(Point p1, Point p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

// Fonction pour calculer la distance d'un pixel par rapport au centre de la fractale
double distance_depuis_centre_fractale(int x, int y, int centre_x, int centre_y)
{
	Point pixel = {x, y};
	Point centre = {centre_x, centre_y};
	return (distance_entre_points(pixel, centre));
}*/