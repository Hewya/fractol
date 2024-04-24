/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabarnou <gabarnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:28:44 by gabarnou          #+#    #+#             */
/*   Updated: 2024/04/24 15:37:18 by gabarnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include <fcntl.h>					/*open, close*/
# include <math.h>					/*fabs*/
# include "minilibx-linux/mlx.h"	/*includes minilibx*/
# include "libft/libft.h"			/*libft...*/

# define SIZE 700

/* KEYCODES & MOUSE CODES */
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define J 38
# define P 35
# define M 46
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
	double	offset_x; // si augmente affichage decaler vers la droite
	double	offset_y; // si augmente affichage decaler vers le haut

	double	zx;
	double	zy;
	double	cx;
	double	cy;

	char	*name;
	int		max_iterations;
}			t_fractal;

/* INIT AND EXIT */
void	init_mlx(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
int		close_all(t_fractal *fractal);
int		free_fractal(t_fractal *fractal);

/* UTILS */
int		key_hooked(int key_code, t_fractal *fractal);
int		mouse_hooked(int mouse_code, int x, int y, t_fractal *fractal);
void	color_pixel(t_fractal *fractal, int x, int y, int color);

/* DISPLAY */
void	*draw_mandelbrot(void *fractal_void);

/* CALCULS_MANDEL */
void	calcul_mandel(t_fractal *fractal);

/* MAIN */
int	main();

#endif
