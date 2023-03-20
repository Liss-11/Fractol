/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:30:55 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/26 13:31:01 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		mouse_press(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == 5)
		data->zoom *= 1.15;
	else if (key == 4)
		data->zoom /= 1.15;
	drawer(data);
	return (0);
}