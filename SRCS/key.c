/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:13:25 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/26 16:13:40 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mlx_keyrelase(int key, t_data *data)
{
	if (key == 257)
		data->shift = 0;
	drawer(data);
	return (1);
}

//dos funciones que buscar las posibilidades que me pueden llegar por key_press
static int	key_press1(int key, t_data *data)
{
	if (key == PLUS)
		data->zoom *= 1.15;
	else if (key == MINUS)
		data->zoom /= 1.15;
	else if(key == 8){
		if (data->name == 'm')
			init_mandelbrot(data);
		if (data->name == 'j'){
			data->zoom = 1.0;
			data->center.x = 0.0;
			data->center.y = 0.0;
		}
	}
	drawer(data);
	return (0);
	//salir y cerrar todo
}

int	key_press(int key, t_data *data)
{
	if (key == ESC || key == 17)
		end_all(data);
	else if (key == ARROW_UP)
		data->center.y += .2 / data->zoom;
	else if (key == ARROW_DOWN)
		data->center.y -= .2 / data->zoom;
	else if (key == ARROW_LEFT)
		data->center.x += .2 / data->zoom;
	else if (key == ARROW_RIGHT)
		data->center.x -= .2 / data->zoom;
	else if (key == 257)
		data->shift = 1;

	else
	{
		ft_printf("key %d", key);
		key_press1(key, data);
	}
	drawer(data);
	ft_printf("key %d", key);
	return (0);
}