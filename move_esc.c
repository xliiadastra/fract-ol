/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_esc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:34:04 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/18 22:52:56 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_esc(int keycode, t_data *data)
{
	double	ax;
	double	ay;

//	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
//		julia_shape(data, keycode);
	ax = (data->xmax - data->xmin) / X_AXIS;
	ay = (data->ymax - data->ymin) / Y_AXIS;
	if (keycode == 53 || keycode == 8)
		color_or_esc(data, keycode);
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 123)
			ax *= -1;
		data->xmin += ax / 0.1;
		data->xmax += ax / 0.1;
	}
	if (keycode == 125 || keycode == 126)
	{
		if (keycode == 125)
			ay *= -1;
		data->ymin += ay / 0.1;
		data->ymax += ay / 0.1;
	}
	check_type(data);
	return (0);
}

void	color_or_esc(t_data *data, int keycode)
{
	if (keycode == 8)
	{
		data->color += 0x00231321;
		check_type(data);
	}
	else
		exit(0);
}
