/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:43:18 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/19 22:33:12 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burning_ship(double a, double b, t_data *data)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (i++ < ITERATION)
	{
		tmp = x;
		x = x * x - y * y + a;
		y = fabs(2 * tmp * y) - b;
		if ((x * x) + (y * y) > 4)
			break ;
	}
	if (i == ITERATION + 1)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, 0xFFFFFF);
	else
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y,
				data->color + (0xe3e3e3 * i));
	}
}

void	burning_ship(t_data *data)
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
			draw_burning_ship(a, b, data);
			data->x++;
		}
		data->y++;
	}
//	mlx_string_put(data->mlx_ptr, data->win_ptr, 699, 9, 0xFFFFFF, "yichoi");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 700, 10, 0x000000, "yichoi");
}

int	creat_ship(void)
{
	t_data	data;

	data.julia_or_mandelbrot = 3;
	data.xmin = MIN_X;
	data.ymin = MIN_Y;
	data.xmax = MAX_X;
	data.ymax = MAX_Y;
	data.color = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, X_AXIS, Y_AXIS, "Burning Ship_Set");
	burning_ship(&data);
	mlx_key_hook(data.win_ptr, move_esc, &data);
	mlx_mouse_hook(data.win_ptr, zoom, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
