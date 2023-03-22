/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:42:49 by afrolova          #+#    #+#             */
/*   Updated: 2023/03/22 17:25:54 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	invalid_input(void)
{
	write(2, "INVALID INPUT\n", 14);
	view_options();
	exit(EXIT_FAILURE);
}

void	invalid_julia_param_input(void)
{
	write(2, "INVALID INPUT\n", 14);
	write(2, "Julia can take as a parameters ONLY numbers,\n", 45);
	write(2, "with values between 3. and -3.\n", 31);
	write(2, "and can use until 6 decimals\n", 29);
	view_options();
	exit(EXIT_FAILURE);
}

void	view_options(void)
{
	ft_printf("\nEither use:\n");
	ft_printf("./fractol mandelbrot\t(for Mandelbrot)\n");
	ft_printf("./fractol tricorn \t(for Tricorn)\n");
	ft_printf("./fractol julia\t\t(for Julia)\n");
	exit(EXIT_FAILURE);
}
