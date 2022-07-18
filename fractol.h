/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:51:21 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/18 21:31:51 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>		// write, read
# include <fcntl.h>			// open, close
# include <stdio.h>			// perror, printf
# include <stdlib.h>		// exit, malloc, free
# include <math.h>			// math
# include "./libft/libft.h"	// libft
# include "mlx.h"			// miniLibx

# define WIN_WIDTH	800
# define WIN_HEIGHT	800
# define MIX_X -2
# define MIX_Y -2
# define MAX_X 2
# define MAX_Y 2
# define ITERATION 130
# define C_A 0.111
# define C_B 0.296

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		color;
	int		julia_or_mandelbrot;
	double	xmin;
	double	xamx;
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

void	ft_error(void);

void	creat_mandelbrot(void);
void	creat_julia(void);
void	creat_ship(void);


#endif
