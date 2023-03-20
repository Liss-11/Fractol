/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:03 by afrolova          #+#    #+#             */
/*   Updated: 2023/03/20 20:51:05 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *data, char **argv)
{
	if (argv[2] && argv[3])
	{
		data->c.r = ft_atod(argv[2], 1.0);
		data->c.i = ft_atod(argv[3], 1.0);
	}
	else
	{
		data->c.r = -0.7;
		data->c.i = 0.27015;
	}
	data->zoom = 1.0;
	data->center.x = 0.0;
	data->center.y = 0.0;
	data->z.x = 0.0;
	data->z.y = 0.0;
	data->tmp.x = 0.0;
	data->tmp.y = 0.0;
	data->mouse1 = 0;
}

void	julia(t_data *data)
{
	int	color;
	int	i;

	data->px.y = -1;
	while (++data->px.y < HEIGHT)
	{
		data->px.x = -1;
		while (++data->px.x < WIDTH)
		{
			data->z.x = 1.5 * (data->px.x - WIDTH / 2) / \
						(0.4 * data->zoom * WIDTH) + data->center.x;
			data->z.y = 1.0 * (data->px.y - HEIGHT / 2) / \
						(0.4 * data->zoom * HEIGHT) + data->center.y;
			i = 256 + data->zoom;
			color = julia_drawer(data, i);
			my_mlx_pixel_put(data, data->px.x, data->px.y, color);
		}
	}
}

int	julia_drawer(t_data *data, int i)
{
	int		color;

	while ((((data->z.x * data->z.x) + (data->z.y * data->z.y)) < 4) && i >= 1)
	{
		data->tmp.x = data->z.x;
		data->tmp.y = data->z.y;
		data->z.x = (data->tmp.x * data->tmp.x) - \
					(data->tmp.y * data->tmp.y) + data->c.r;
		data->z.y = 2.0 * data->tmp.x * data->tmp.y + data->c.i;
		i--;
	}
	if (i < 1)
		color = 0x000000;
	else
		color = ((i & 0xFF) << 26) + ((i & 0xFF) << 13) + (i & 0xFF);
	return (color);
}
