/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:44:30 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:58:48 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int i)
{
	if (i > 0)
	{
		ft_putendl_fd("Fractol: ./fractol <Name of the fractal>", 1);
		ft_putendl_fd("Fractals can be: mandel, julia, autre", 1);
		ft_putendl_fd("For julia needs 2 parametres (-0.745429 0.05)", 1);
	}
}

bool	is_valid_input(const char *str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == ','
				|| *str == '.' || *str == '+' || *str == '-'))
			return (false);
		str++;
	}
	return (true);
}

void	check_params(int ac, char **av)
{
	if ((((ft_strcmp(av[1], "mandel") == 0) || (ft_strcmp(av[1], "ship") == 0))
			&& (ac != 2)) || ((ft_strcmp(av[1], "julia") == 0) && (ac != 4)))
	{
		ft_error(1);
		exit(1);
	}
	if ((ft_strcmp(av[1], "julia") == 0)
		&& (!is_valid_input(av[2]) || !is_valid_input(av[3])))
	{
		ft_putendl_fd("Invalid input", 1);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	check_params(ac, av);
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
	return (0);
}
