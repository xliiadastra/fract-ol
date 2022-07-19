/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:24:51 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/19 23:09:01 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_type(t_data *data)
{
	if (data->julia_or_mandelbrot == 1)
		mandelbrot(data);
	if (data->julia_or_mandelbrot == 2)
		julia(data);
	if (data->julia_or_mandelbrot == 3)
		burning_ship(data);
}

void	julia_shape(t_data *data, int keycode)
{
	if (keycode == 0)
		data->jx -= 0.1;
	if (keycode == 1)
		data->jy -= 0.1;
	if (keycode == 2)
		data->jx += 0.1;
	if (keycode == 13)
		data->jy += 0.1;
}

void	ft_error(void)
{
	printf("\nusage: \"./fractol fractals\"\n\n");
	exit(1);
}
