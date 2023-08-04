/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:45 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/26 16:00:49 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

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
	t_data data;

	if (!strncmp(argv[1], "j", 0xFFFFFFFF))
		data.name = 'j';
	else if (!strncmp(argv[1], "m", 0xFFFFFFFF))
		data.name = 'm';
	ft_printf("Init programm, the name is: %c\n", data.name);

	init_fractal(&data, argv);
	if (!create_window(&data))
		return (0);
	if (!execute_program(&data))
		return (0);	
	return (1);
}

int	execute_program(t_data *data)
{
	ft_printf("I'm executing the program\n");
	drawer(data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, mlx_keyrelase, data);
	mlx_hook(data->win, 4, 0, mouse_scroll, data);
	mlx_hook(data->win, ON_DESTROY, 0, end_all, data); 


//	mlx_loop_hook(data->win, mouse_detector, data);

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

void	view_options()
{
	ft_printf("\nWRONG INPUT, eiher use:\n\n");
	ft_printf("./fractol m\t(for Mandelbrot)\n");
	ft_printf("./fractol j\t\t(for Julia)\n");
	exit(EXIT_FAILURE);
}
