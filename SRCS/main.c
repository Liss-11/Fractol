/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:45 by afrolova          #+#    #+#             */
/*   Updated: 2023/03/20 21:23:31 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		invalid_input();
	if (!check_errors(argc, argv))
		exit (EXIT_FAILURE);
	if (!init_program(argv))
		exit (EXIT_FAILURE);
	exit (EXIT_SUCCESS);
	return (0);
}

int	init_program(char **argv)
{
	t_data	data;

	data.name = argv[1];
	init_fractal(&data, argv);
	if (!create_window(&data))
		return (0);
	if (!execute_program(&data))
		return (0);
	return (1);
}

int	execute_program(t_data *data)
{
	drawer(data);
	mlx_hook(data->win, 2, 0, key_enter, data);
	mlx_hook(data->win, 4, 0, mouse_press, data);
	mlx_hook(data->win, ON_DESTROY, 0, end_all, data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	return (1);
}

int	end_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(EXIT_FAILURE);
	return (0);
}
