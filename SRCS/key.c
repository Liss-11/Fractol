/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:13:25 by afrolova          #+#    #+#             */
/*   Updated: 2023/06/01 15:08:45 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	key_enter1(int key, t_data *data)
{
	if (key == PLUS)
		data->zoom *= 1.15;
	else if (key == MINUS)
		data->zoom /= 1.15;
	else if (key == 8)
	{
		data->zoom = 1.0;
		data->center.x = -0.5;
		data->center.y = 0.0;
	}
	drawer(data);
	return (0);
}

int	key_enter(int key, t_data *data)
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
	else
		key_enter1(key, data);
	drawer(data);
	return (0);
}
