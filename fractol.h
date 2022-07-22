/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:51:21 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/23 01:19:50 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "./libft/libft.h"
# include "mlx.h"

# define X_AXIS	800
# define Y_AXIS	800
# define MIN_X -2
# define MIN_Y -2
# define MAX_X 2
# define MAX_Y 2
# define ITERATION 130

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		color;
	int		julia_or_mandelbrot;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	jx;
	double	jy;
}	t_data;

typedef struct images
{
	void	*mlx;
	void	*win;
	void	*image;
	void	*path;
	int		width;
	int		height;
	int		ret;
}	t_img;

void	tutorial(void);
void	home(void);
void	check_type(t_data *data);

void	ft_error(void);

void	creat_mandelbrot(void);
void	mandelbrot(t_data *data);
void	draw_mandelbrot(double a, double b, t_data *data);

void	creat_julia(void);
void	julia(t_data *data);
int		julia_set(double a, double b, t_data *data);
void	julia_shape(t_data *data, int keycode);

void	creat_ship(void);
void	burning_ship(t_data *data);
void	draw_burning_ship(double a, double b, t_data *data);

int		zoom(int keycode, int x, int y, t_data *data);
int		move_esc(int keycode, t_data *data);
void	color_or_esc(t_data *data, int keycode);

#endif
