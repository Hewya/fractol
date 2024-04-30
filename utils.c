/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:00 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/30 17:36:03 by gabarnou         ###   ########.fr       */
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


