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


int		mouse_scroll(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == 5){
		ft_printf("key em key5: %d\n", key);
		data->zoom *= 1.15;
	}
	else if (key == 4)
	{
		ft_printf("key en key4: %d\n", key);
		data->zoom /= 1.15;
	
	}
	ft_printf("key: %d\n", key);
	drawer(data);
	return (0);
}

int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y)
{

	
}

//interesante, para los colores

/* int		mlx_int_get_good_color(t_xvar *xvar,int color)
{
  XColor	xc;

  if (xvar->depth>=24)
    return (color);
  xc.red = (color>>8)&0xFF00;
  xc.green = color&0xFF00;
  xc.blue = (color<<8)&0xFF00;
  xc.pixel = ((xc.red>>(16-xvar->decrgb[1]))<<xvar->decrgb[0])+
    ((xc.green>>(16-xvar->decrgb[3]))<<xvar->decrgb[2])+
    ((xc.blue>>(16-xvar->decrgb[5]))<<xvar->decrgb[4]);
  return (xc.pixel);
} */