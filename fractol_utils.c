/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:24:51 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/18 22:48:57 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_type(t_data *data)
{
	if (data->julia_or_mandelbrot == 1)
		mandelbrot(data);
//	if (data->julia_or_mandelbrot == 2)
//		julia(data);
//	if (data->julia_or_mandelbrot == 3)
//		burning_ship(data);
}
