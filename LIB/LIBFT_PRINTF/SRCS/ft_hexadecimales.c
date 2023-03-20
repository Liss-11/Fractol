/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimales.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:55:27 by afrolova          #+#    #+#             */
/*   Updated: 2022/07/13 16:14:14 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	to_hexadecimal(unsigned int n, char str, int *we)
{
	char	*arr;
	int		re;

	if (str == 'x')
		arr = "0123456789abcdef";
	if (str == 'X')
		arr = "0123456789ABCDEF";
	re = n % 16;
	if (n < 16)
		return (ft_write (1, &arr[re], 1, we));
	return (to_hexadecimal(n / 16, str, we) + ft_write(1, &arr[re], 1, we));
}

int	to_hexadecimal_ptr(unsigned long long n, int *we)
{
	char	*arr;
	int		re;
	ssize_t	s;

	arr = "0123456789abcdef";
	re = n % 16;
	if (n < 16)
	{
		s = ft_write(1, &arr[re], 1, we);
		return (s);
	}
	return (to_hexadecimal_ptr(n / 16, we) + ft_write(1, &arr[re], 1, we));
}

int	ft_write_pointer(unsigned long long n, int *we)
{
	int	len;

	len = 0;
	len = ft_write(1, "0x", 2, we);
	len += to_hexadecimal_ptr(n, we);
	return (len);
}
