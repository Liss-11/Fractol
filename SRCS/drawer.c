/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:14:23 by afrolova          #+#    #+#             */
/*   Updated: 2023/03/20 20:54:06 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	drawer(t_data *data)
{	
	background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (!strncmp(data->name, "mandelbrot", 0xFFFFFFFF))
		mandelbrot(data);
	else if (!strncmp(data->name, "julia", 0xFFFFFFFF))
		julia(data);
	else if (!strncmp(data->name, "tricorn", 0xFFFFFFFF))
		tricorn(data);
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
	*(unsigned int *)dst = color;
}

int	gradient(int startcolor, int endcolor, int len, int i)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((endcolor >> 16) - \
					(startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + ft_round(i * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(i * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(i * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}
