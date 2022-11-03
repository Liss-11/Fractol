/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:42:49 by afrolova          #+#    #+#             */
/*   Updated: 2022/11/02 22:42:53 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	invalid_input(void)
{
	write(2, "INVALID INPUT\n", 14);
	view_options();
	exit(EXIT_FAILURE);
}

void	invalid_julia_param_input(void)
{
	write(2, "INVALID INPUT\n", 14);
	ft_printf("Julia can take as a parameters ONLY numbers,\n");
	ft_printf("with values between 3 and -3, and can use until 3 decimals");
	view_options();
	exit(EXIT_FAILURE);
}

