/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:42:24 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/10/11 20:11:52 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closewindow(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		closewindow(fractal);
	if (keysym == XK_Left)
		fractal->changed_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->changed_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->changed_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->changed_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations += 10;
	else if (keysym == XK_minus)
		fractal->iterations -= 10;
	fractal_render(fractal);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	track_julia(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (escale(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->changed_x;
		fractal->julia_y = (escale(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->changed_y;
		fractal_render(fractal);
	}
	return (0);
}
