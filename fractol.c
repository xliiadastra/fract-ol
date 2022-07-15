/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:49:49 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/15 20:02:29 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	if (argc < 2 || check_input(argv[1]))
		ft_error();
	if (argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 11))
		creat_mandelbrot();
//	else if (argc == 4 && ft_strncmp(argv[1], "Julia", 6))
//		creat_julia(ft_atof(argv[2], ft_atof(argv[3])));
//	else if (argc == 4 && ft_strncmp(argv[1], "Burning ship", 13))
//		creat_ship(ft_atof(argv[2], ft_atof(argv[3])));
	else
		ft_error();
	return (0);
}
