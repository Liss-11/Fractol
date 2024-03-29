/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:37:55 by afrolova          #+#    #+#             */
/*   Updated: 2023/03/22 17:20:48 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../INC/fractol.h"

static int	check_if_mandel(char *argv)
{
	if (!strncmp(argv, M, 0xFFFFFFFF))
		return (1);
	return (0);
}

static int	check_if_tricorn(char *argv)
{
	if (!strncmp(argv, T, 0xFFFFFFFF))
		return (1);
	return (0);
}

static int	check_params_julia(char *argv)
{
	if (*argv == '-')
		argv++;
	if (strlen(argv) > 9)
		invalid_julia_param_input();
	else
		if (*argv > '3' || *argv < '0')
			invalid_julia_param_input();
	argv++;
	if (*argv && *argv == '.')
		argv++;
	else if (*argv)
		invalid_julia_param_input();
	while (*argv)
	{
		if (*argv > '9' || *argv < '0')
			invalid_julia_param_input();
		argv++;
	}
	return (1);
}

static int	check_if_julia(char *argv)
{
	if (!strncmp(argv, J, 0xFFFFFFFF))
		return (1);
	return (0);
}

int	check_errors(int argc, char **argv)
{
	if (argc == 2 && (check_if_mandel(argv[1]) || check_if_julia(argv[1]) || \
		check_if_tricorn(argv[1])))
		return (1);
	if (argc == 4 && check_if_julia(argv[1]))
	{
		if (check_params_julia(argv[2]) && check_params_julia(argv[3]))
			return (1);
		else
			invalid_input();
	}
	else
		invalid_input();
	return (0);
}
