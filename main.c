/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:44:30 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/25 16:43:39 by gabarnou         ###   ########.fr       */
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
	ft_putendl_fd("entrer", 1);
	fractal = malloc(sizeof(t_fractal));
	init_mlx(fractal);
	fractal->name = av[1];
	ft_putendl_fd("init_mlx", 1);
	init_fractal(fractal);
	ft_putendl_fd("init_fractal", 1);
	mlx_key_hook(fractal->window, key_hooked, fractal);
	ft_putendl_fd("key_hook", 1);
	mlx_mouse_hook(fractal->window, mouse_hooked, fractal);
	ft_putendl_fd("mouse_hook", 1);
	mlx_hook(fractal->window, 17, 0L, close_all, fractal);
	ft_putendl_fd("close window", 1);
	draw_fractal(fractal, fractal->name);
	ft_putendl_fd("draw", 1);
	mlx_loop(fractal->mlx);
	ft_putendl_fd("loop", 1);
	return(0);
}
