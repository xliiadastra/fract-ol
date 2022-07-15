/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:25:13 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/15 20:04:03 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	printf("usage: \"./fractol [fractal]\"\nfractal :\n"
			"--> Mandelbrot\n"
			"--> Julia 'a' 'b'\n"
			"--> Burning ship 'a' 'b'\n");
	exit(1);
}

int	check_input(char *str)
{
	if (!str)
		return (2);
	if (str[0] == 'M')
		return (ft_strncmp(str, "Mandelblot", 11));
	else if (str[0] == 'J')
		return (ft_strncmp(str, "Julia", 6));
	else if (str[0] == 'B')
		return (ft_strncmp(str, "Burning ship", 13));
	else
		return (2);
}

double ft_atof(const char *str)
{
	int	i;
	int	dot;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + sign * (str[i++] - '0');
	if (str[i] == '.')
		i++;
	dot = i;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + sign * (str[i++] - '0');
	return ((double)result / pow(10, i - dot));
}
