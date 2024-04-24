/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:44:30 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/24 15:40:39 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	init_mlx(fractal);
	init_fractal(fractal);
	mlx_key_hook(fractal->window, key_hooked, fractal);
	mlx_mouse_hook(fractal->window, mouse_hooked, fractal);
	mlx_hook(fractal->window, 17, 1L << 17, close_all, fractal); 

	// LANCER CALCUL ET AFFICHAGE
	mlx_loop(fractal->mlx);
	return(0);
}