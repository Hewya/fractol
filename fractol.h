/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:28:44 by gabarnou          #+#    #+#             */
/*   Updated: 2024/05/06 12:56:41 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>					/*open, close*/
# include <math.h>					/*fabs*/
# include <stdlib.h>				/* abs */
# include <stdbool.h>
# include "minilibx-linux/mlx.h"	/*includes minilibx*/
# include "libft/libft.h"			/*libft...*/
# include "X11/keysym.h"

# define SIZE 1200

/* MOUSE CODES */
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/*  STRUCTURES */
typedef struct s_fractal
{
	void	*mlx;
	void	*window;

	void	*img;
	void	*addr_img;
	int		bits_per_pixel;
	int		lenght_line;
	int		endian;

	int		x;
	int		y;
	int		color;
	double	zoom;
	double	offset_x;
	double	offset_y;

	double	zx;
	double	zy;
	double	cx;
	double	cy;

	char	*name;
	int		max_iterations;
}			t_fractal;

/* INIT_EXIT */
void	init_mlx(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
int		close_all(t_fractal *fractal);
int		free_fractal(t_fractal *fractal);

/* UTILS */
int		key_hooked(int key_code, t_fractal *fractal);
int		mouse_hooked(int mouse_code, int x, int y, t_fractal *fractal);
double	ft_atod(char *str);

/* DISPLAY */
int		draw_fractal(t_fractal *fractal, char *str);
void	*draw_mandelbrot(void *fractal_void);
void	draw_julia(t_fractal *fractal);
void	draw_ship(t_fractal *fractal);

/* COLORS */
void	color_pixel(t_fractal *fractal, int x, int y, int color);

/* CALCULS_MANDEL */
void	calcul_mandel(t_fractal *fractal);

/* CALCULS_JULIA */
void	calcul_julia(t_fractal *fractal);

/* CALCULS_SHIP */
void	calcul_ship(t_fractal *fractal);

/* MOVES */
void	zoom(t_fractal *fractal, int x, int y, int zoom);

/* MAIN */
int		main(int ac, char **av);
void	check_params(int ac, char **av);
void	ft_error(int i);
bool 	is_valid_input(const char *str);

#endif
