/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:42:13 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/22 21:21:05 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(double a, double b, t_data *data)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	x = a;
	y = b;
	i = 0;
	while (i < ITERATION)
	{
		tmp = x;
		x = ((x * x) - (y * y)) + data->jx;
		y = (2 * tmp * y) + data->jy;
		if ((x * x) + (y * y) > 4)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y,
				data->color + (0xccf1ff * i));
			return (0);
		}
		i++;
	}
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, 0xFFFFFF);
	return (0);
}

void	julia(t_data *data)
{
	double	a;
	double	b;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->y = 0;
	while (data->y <= Y_AXIS)
	{
		data->x = 0;
		while (data->x <= X_AXIS)
		{
			a = data->xmin + (data->x * ((data->xmax - data->xmin) / X_AXIS));
			b = data->ymax - (data->y * ((data->ymax - data->ymin) / Y_AXIS));
			julia_set(a, b, data);
			data->x++;
		}
		data->y++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 699, 9, 0x000000, "yichoi");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 700, 10, 0xFFFFFF, "yichoi");
}

void	creat_julia(void)
{
	t_data	data;

	data.julia_or_mandelbrot = 2;
	data.xmin = MIN_X;
	data.ymin = MIN_Y;
	data.xmax = MAX_X;
	data.ymax = MAX_Y;
	data.jx = 0;
	data.jy = 0;
	data.color = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, X_AXIS, Y_AXIS, "Julia_Set");
	julia(&data);
	mlx_key_hook(data.win_ptr, move_esc, &data);
	mlx_mouse_hook(data.win_ptr, zoom, &data);
	mlx_loop(data.mlx_ptr);
}
