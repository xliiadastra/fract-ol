/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:49:49 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/21 19:33:16 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tutorial(void)
{
	printf("\n**                tutorial                      **\n");
	printf("** You can use arrows to move : ← ↑ → ↓         **\n");
	printf("** Mouse Wheel can zoom in and out              **\n");
	printf("** C Key Will Change the color in all fractals  **\n");
	printf("** For Julia (A,W,S,D) to change the shape      **\n");
}

int	choice(int keycode, t_img *t)
{
	if (keycode == 53)
	{
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	if (keycode == 18 || keycode == 83)
		creat_mandelbrot();
	if (keycode == 19 || keycode == 84)
		creat_julia();
	if (keycode == 20 || keycode == 85)
		creat_ship();
	return (0);
}

void	home(void)
{
	t_img	t;

	t.path = "./IMG/tutorial_fractol.xpm";
	t.mlx = mlx_init();
	t.image = mlx_xpm_file_to_image(t.mlx, t.path, &t.width, &t.height);
	t.win = mlx_new_window(t.mlx, 600, 600, "Fractal's");
	mlx_put_image_to_window(t.mlx, t.win, t.image, 0, 0);
	mlx_key_hook(t.win, choice, &t);
	mlx_loop(t.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		ft_error();
	if (!ft_strncmp(argv[1], "fractals", 9))
	{
		tutorial();
		home();
	}
	else if (!ft_strncmp(argv[1], "Mandelbrot", 11))
	{
		tutorial();
		creat_mandelbrot();
	}
	else if (!ft_strncmp(argv[1], "Julia", 6))
	{
		tutorial();
		creat_julia();
	}
	else if (!ft_strncmp(argv[1], "Burning_ship", 13))
	{
		tutorial();
		creat_ship();
	}
	else
		ft_error();
	return (0);
}
