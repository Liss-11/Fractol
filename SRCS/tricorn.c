/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:30:55 by afrolova          #+#    #+#             */
/*   Updated: 2023/03/22 16:55:42 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	tricorn(t_data *data)
{
	int	color;
	int	i;

	data->px.y = -1;
	while (++data->px.y < HEIGHT)
	{
		data->px.x = -1;
		while (++data->px.x < WIDTH)
		{
			data->c.r = 1.5 * (data->px.x - WIDTH / 2) / \
						(0.4 * data->zoom * WIDTH) + data->center.x;
			data->c.i = 1.0 * (data->px.y - HEIGHT / 2) / \
						(0.4 * data->zoom * HEIGHT) + data->center.y;
			i = MAX_ITER + data->zoom;
			color = tricorn_drawer(data, i);
			my_mlx_pixel_put(data, data->px.x, data->px.y, color);
		}
	}
}

int	tricorn_drawer(t_data *data, int i)
{
	int		color;

	data->z.x = data->c.r;
	data->z.y = data->c.i;
	while ((((data->z.x * data->z.x) + (data->z.y * data->z.y)) < 4) && i >= 1)
	{
		data->tmp.x = data->z.x;
		data->tmp.y = data->z.y;
		data->z.x = (data->tmp.x * data->tmp.x) - \
					(data->tmp.y * data->tmp.y) + data->c.r;
		data->z.y = -2.0 * data->tmp.x * data->tmp.y + data->c.i;
		i--;
	}
	if (i < 1)
		color = 0x000000;
	else
	{
		color = gradient(START_COLOR, END_COLOR, MAX_ITER, i);
		color = ((color & 0xFF) << 20) + ((color & 0xFF) << 13) + \
				(color & 0xFF);
	}
	return (color);
}
