/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:14 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/26 16:58:26 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

//mira de que fractal se trata i segun el nombre le asigna unos valores o otros
void	init_fractal (t_data *data, char **argv)
{
	//(void)argv;
	ft_printf("INIT FRACTAL\n");
	if (!strncmp(data->name, "mandelbrot", 0xFFFFFFFF))
	{
		(void)argv;
		ft_printf("Compare funciona, detecta mandelbrot\n");
		init_mandelbrot(data);
	}
	if (!strncmp(data->name, "julia", 0xFFFFFFFF))
	{
		ft_printf("Compare funciona, detecta julia\n");
		init_julia(data, argv);
	}
}

int	create_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->buffer = mlx_get_data_addr(data->img, &data->bpp,
	 &data->llen, &data->endian);
	if (!data->buffer)
		return (0);
	return (1);
}

/*double	ft_atod(char *str)
{
	int		i;
	double	num;
	int		len;

	num = 0.0;
	i = 1;
	if (*str == '-')
	{
		i *= -1;
		str++;
	}
	len = strlen(str);
	while (len > 0)
	{
		len--;
		num = str[len];
		num``
		10 * len;

	}
	return ();
}*/