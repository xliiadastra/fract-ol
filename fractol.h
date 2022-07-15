/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:51:21 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/15 20:07:45 by yichoi           ###   ########.fr       */
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
# define WIN_HEIGHT	600
# define ITER_MAX	100
# define KEY_A		0
# define KEY_D		2
# define KEY_F		3
# define KEY_C		8
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126
# define KEY_PLUS	24
# define KEY_MINUS	27
# define ZOOM_IN	34
# define ZOOM_OUT	31
# define KEY_ESC	53

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		type;
	int		x;
	int		y;
	int		press_f;
	int		color;
	int		bpp;
	int		size_line;
	int		endian;
	double	a;
	double	b;
	double	zoom_rate;
}	t_data;

void	ft_error(void);
int		check_input(char *str);
double	ft_atof(const char *str);

void	data_init(t_data *data);

void	creat_mandelbrot(void);

#endif
