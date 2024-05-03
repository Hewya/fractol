/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:44:30 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/03 15:35:41 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	if ((((ft_strcmp(av[1], "mandel") == 0) || (ft_strcmp(av[1], "autre") == 0))
			 && (ac != 2)) || ((ft_strcmp(av[1], "julia") == 0) && (ac != 4)))
	{
		ft_putendl_fd("Fractol: ./fractol <Name of the fractal>", 1);
		ft_putendl_fd("Fractals can be: mandel, julia, autre", 1);
		ft_putendl_fd("For julia needs name + 2 parametres (-0.745429 0.05)", 1);
		return(0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_mlx(fractal);
	fractal->name = av[1];
	init_fractal(fractal);
	mlx_key_hook(fractal->window, key_hooked, fractal);
	mlx_mouse_hook(fractal->window, mouse_hooked, fractal);
	mlx_hook(fractal->window, 17, 0L, close_all, fractal);
	if (ft_strcmp(fractal->name, "julia") == 0)
	{
		fractal->cx = ft_atod(av[2]);
		fractal->cy = ft_atod(av[3]);
	}
	draw_fractal(fractal, fractal->name);
	mlx_loop(fractal->mlx);
	return(0);
}
