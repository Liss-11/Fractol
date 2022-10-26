/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:14:23 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/26 16:14:38 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//hacer las iteraciones para los colores - my_pixel_put();

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->buffer + (y * data->llen + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	drawer(t_data *data)
{
	
	background(data);
	ft_printf("I'm in DRAWING\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_printf("\nCOMPARE: <%s> with <mandelbrot>\n", data->name);
	if (!strncmp(data->name, "mandelbrot", 0xFFFFFFFF))
		mandelbrot(data);
/*	else if (strncmp(data->name, "julia", 0xFFFFFFFF))
		julia();*/
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	background(t_data *data)
{
	int	color;

	data->px.y = -1;
	while (++data->px.y < HEIGHT)
	{
		data->px.x = -1;
		while (++data->px.x < WIDTH)
		{
			color = 0;
			//my_pixel_put(data, data->px.x, data->px.y, color);
			//mlx_pixel_put(data->mlx, data->win, 2, 2, color);
			my_mlx_pixel_put(data, data->px.x, data->px.y, color);
		}
	}
	ft_printf("Printing background\n");
}
