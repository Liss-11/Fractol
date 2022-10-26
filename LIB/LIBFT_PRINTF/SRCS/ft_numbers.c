/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:54:23 by afrolova          #+#    #+#             */
/*   Updated: 2022/07/12 14:53:45 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_printn(long long n, int sign, int *we)
{
	char	c;

	c = n % 10 + '0';
	if (n < 10)
	{
		return (ft_write(1, "-", sign, we) + ft_write(1, &c, 1, we));
	}
	return (ft_printn(n / 10, sign, we) + ft_write(1, &c, 1, we));
}

int	ft_putnbr(int n, int *we)
{
	long long	nbr;

	nbr = (long long)n;
	if (nbr < 0)
	{
		return (ft_printn(nbr * -1, 1, we));
	}
	return (ft_printn(n, 0, we));
}

int	ft_putnbr_unsigned(unsigned int n, int *we)
{
	char	c;

	c = (n % 10) + '0';
	if (n < 10)
		return (ft_write(1, &c, 1, we));
	return (ft_putnbr_unsigned(n / 10, we) + ft_write(1, &c, 1, we));
}
