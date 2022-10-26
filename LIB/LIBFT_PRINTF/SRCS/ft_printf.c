/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:32:05 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/30 23:36:14 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	return_value(va_list ptr, char const *str, int *we)
{
	if (*str == '%')
		return (ft_write(1, "%", 1, we));
	if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(ptr, int), we));
	if (*str == 'c')
		return (my_putchar(va_arg(ptr, int), we));
	if (*str == 'u')
		return (ft_putnbr_unsigned(va_arg(ptr, unsigned int), we));
	if (*str == 's')
		return (ft_strlen_print(va_arg(ptr, char *), we));
	if (*str == 'x' || *str == 'X')
		return (to_hexadecimal(va_arg(ptr, unsigned int), *str, we));
	if (*str == 'p')
		return (ft_write_pointer(va_arg(ptr, unsigned long long), we));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		len;
	va_list	ptr;
	int		we;

	va_start(ptr, str);
	we = 0;
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			len += return_value(ptr, ++str, &we);
		else
		{
			if (write(1, str, 1) != 1)
				return (-1);
			len++;
		}
		if (we)
			return (-1);
		str++;
	}
	va_end (ptr);
	if (we)
		return (-1);
	return (len);
}
