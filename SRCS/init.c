/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:14 by afrolova          #+#    #+#             */
/*   Updated: 2023/03/22 16:53:47 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	init_fractal(t_data *data, char **argv)
{
	ft_printf("INIT FRACTAL\n");
	if (!strncmp(data->name, "mandelbrot", 0xFFFFFFFF))
	{
		(void)argv;
		init_mandelbrot(data);
	}
	if (!strncmp(data->name, "tricorn", 0xFFFFFFFF))
	{
		(void)argv;
		init_mandelbrot(data);
	}
	if (!strncmp(data->name, "julia", 0xFFFFFFFF))
		init_julia(data, argv);
}

int	create_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->buffer = mlx_get_data_addr(data->img, &data->bpp, \
	&data->llen, &data->endian);
	if (!data->buffer)
		return (0);
	return (1);
}

double	ft_atod(char *str, double sign)
{
	double	num;
	double	ten;

	num = 0.0;
	ten = 1.0;
	if (*str == '-' && str++)
		sign *= -1.0;
	num += (double)(*str - '0');
	if (*(str + 1) == '.' && str++)
	{
		while (*++str)
			num += ((double)(*str - '0') / (ten *= 10));
	}
	return (num * sign);
}
