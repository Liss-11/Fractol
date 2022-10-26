/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:46:39 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/26 15:47:04 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_data *data)
{
	data->zoom = 1.0;
	data->center.x = -0.5;
	data->center.y = 0.0;
	data->c.r = 0.0;
	data->c.i = 0.0;
	data->z.x = 0.0;
	data->tmpz.y= 0.0;
	ft_printf("Mandelbrot inicializado\n");
	//.........
}

void	mandelbrot(t_data *data)
{
	int color;

	data->px.y = -1;
	while (++data->px.y < HEIGHT)
	{
		data->px.x = -1;
		while (++data->px.x < WIDTH)
		{
			data->c.r = 1.5 * (data->px.x - WIDTH / 2) / (0.4 * data->zoom * WIDTH) + data->center.x;
			data->c.i = 1.0 * (data->px.y - HEIGHT / 2) / (0.4 * data->zoom * HEIGHT) + data->center.y;
		
			//tiene que depender del data->zoom - en el .h puedo poner una relacion....!
			color = mandelbrot_drawer(data, MAX_ITER);
			my_mlx_pixel_put(data, data->px.x, data->px.y, color);
		//	mlx_pixel_put(data->mlx, data->win, data->px.x, data->px.y, color);
		}
	}
}

int	mandelbrot_drawer(t_data *data, int i)
{
	double	tmp_x;
	int		color;

	tmp_x = 0;
	data->z.x = data->c.r;
	data->tmpz.y = data->c.i;
	
	while ((((data->z.x * data->z.x) + (data->tmpz.y * data->tmpz.y)) < 4) && i >= 1)
	{
		tmp_x = (data->z.x * data->z.x) - (data->tmpz.y * data->tmpz.y) + data->c.r;
		data->tmpz.y = 2.0 * data->z.x * data->tmpz.y + data->c.i;
		data->z.x = tmp_x;
		i--;
	}
//	ft_printf("\nI vaue: %d\n", i);
	if (i < 1)
		color = 0x000000;
	else
		color = ((i & 0xFF)<<26) + ((i & 0xFF)<<13) + (i & 0xFF);
	return(color);
}

//img_pixel_put(&data->img, x, (y + 10), RGBA(255, 0, 0, 125));