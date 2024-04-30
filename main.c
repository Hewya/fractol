/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:44:30 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/30 16:54:25 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	if(ac != 2)
	{
		ft_putendl_fd("Fractol: ./fractol <name of the fractal>", 1);
		ft_putendl_fd("fractals can be: mandel, julia, autre", 1);
		return(0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_mlx(fractal);
	fractal->name = av[1];
	init_fractal(fractal);
	mlx_key_hook(fractal->window, key_hooked, fractal);
	mlx_mouse_hook(fractal->window, mouse_hooked, fractal);
	mlx_hook(fractal->window, 17, 0L, close_all, fractal);
	draw_fractal(fractal, fractal->name);
	mlx_loop(fractal->mlx);
	return(0);
}
