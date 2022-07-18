/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:11:00 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/18 22:48:17 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int keycode, int x, int y, t_data *data)
{
	double	ax;
	double	ay;

	printf("%d-->\t(%d,%d)\n", keycode, x, y);
	ax = (data->xmax - data->xmin) / X_AXIS;
	ay = (data->ymax - data->ymin) / Y_AXIS;
	if (keycode == 5)
	{
		data->xmin = (data->xmin + ((ax * x) * 0.2));
		data->ymin = (data->ymin + ((ay * (Y_AXIS - y)) * 0.2));
		data->xmax = (data->xmax - ((ax * (X_AXIS - x)) * 0.2));
		data->ymax = (data->ymax - ((ay * y) * 0.2));
	}
	if (keycode == 4)
	{
		data->xmin = (data->xmin - 0.2);
		data->ymin = (data->ymin - 0.2);
		data->xmax = (data->xmax + 0.2);
		data->ymax = (data->ymax + 0.2);
	}
	check_type(data);
	return (0);
}
