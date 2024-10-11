/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:33:46 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/10/11 20:05:30 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define RED 0xFF0000
# define GREEN 0xFF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define YELLOW 0xFFFF00

# define WIDTH 600
# define HEIGHT 600

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	zoom;
	double	escape_value;
	int		iterations;
	int		color;
	double	changed_x;
	double	changed_y;
	double	julia_x;
	double	julia_y;
}	t_fractal;

t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
double		atod(char *s);

double		escale(double element, double new_min,
				double new_max, double old_max);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int x, int y, t_fractal *fractal);

int			closewindow(t_fractal *fractal);
int			handle_key(int keysym, t_fractal *fractal);
int			handle_mouse(int button, int x, int y, t_fractal *fractal);
int			track_julia(int x, int y, t_fractal *fractal);

void		data_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);

#endif