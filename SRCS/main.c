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
	char	*name;

	name = argv[1];
	(void)argc;

	//vemos los posibles errores en entrada de parametros sin inicializar nada
//	if (!check_errors(argc, argv, &name))
//		exit (EXIT_FAILURE);
	if (!init_program(argv, name))
		exit (EXIT_FAILURE);
	return (0);
	exit (EXIT_SUCCESS);
}

int	init_program(char **argv, char *name)
{
	t_data data;

	data.name = name;
	(void)argv;

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
	mandelbrot(data);
	mlx_key_hook(data->win, key_enter, data);
	mlx_hook(data->win, ON_DESTROY, 0, end_all, data);
//	see_hooks(data);
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

void	usage(void)
{
	ft_printf("\nWRONG INPUT, eiher use:\n\n");
	ft_printf("./fractol mandelbrot\t(for Mandelbrot)\n");
	ft_printf("./fractol julia\t\t(for Julia)\n");
	exit(EXIT_FAILURE);
}