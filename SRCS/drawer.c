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

void	drawer(t_data *data)
{	
	background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (data->name == 'm')
		mandelbrot(data);
	else if (data->name == 'j')
		julia(data);
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
			my_mlx_pixel_put(data, data->px.x, data->px.y, color);
		}
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->buffer + (y * data->llen + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
