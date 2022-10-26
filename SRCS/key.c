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

//dos funciones que buscar las posibilidades que me pueden llegar por key_press
static int	key_enter1(int key, t_data *data)
{
	if (key == PLUS)
		data->zoom *= 1.15;
	else if (key == MINUS)
		data->zoom /= 1.15;
	
/*	else if(key == 2)
	{
		init_mandelbrot();
	}*/

	drawer(data);
	return (0);
	//salir y cerrar todo
}

int	key_enter(int key, t_data *data)
{
	if (key == ESC)
		end_all(data);
	//llama la funcio de salir y cerrar todo
	else if (key == ARROW_UP)
		data->center.y += .2 / data->zoom;
	//muevo hacia arriba
	else if (key == ARROW_DOWN)
	//muevo hacia bajao
		data->center.y -= .2 / data->zoom;
	else if (key == ARROW_LEFT)
	//izquierda
			data->center.x += .2 / data->zoom;
	else if (key == ARROW_RIGHT)
	//derecha
		data->center.x -= .2 / data->zoom;
	else
	{
		ft_printf("key %d", key);
		key_enter1(key, data);
	}
	drawer(data);
	ft_printf("key %d", key);
	return (0);
}