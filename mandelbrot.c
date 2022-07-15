/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:41:22 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/15 20:05:28 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	creat_mandelbrot(void)
{
	t_data	data;

	data_init(&data);
	data.type = 0;
	mlx_key_hook(data.win, press_key, &data);
	mlx_mouse_hook(data.win, mouse_button, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.win);
}
