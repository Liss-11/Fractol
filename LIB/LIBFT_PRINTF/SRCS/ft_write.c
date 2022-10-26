/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:48:08 by afrolova          #+#    #+#             */
/*   Updated: 2022/07/12 16:04:09 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_write(int fd, char *c, int i, int *we)
{
	int	tl;

	tl = 0;
	if (*we == 0)
	{
		tl = write(fd, c, i);
		if (tl == -1)
		{
			*we = 1;
			return (-1);
		}
		return (i);
	}
	return (0);
}

int	my_putchar(int c, int *we)
{
	if (write (1, &c, 1) != 1)
		*we = 1;
	return (1);
}

int	ft_strlen_print(char *str, int *we)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_write(1, "(null)", 6, we));
	if (!str[i])
		return (0);
	while (str[i] != '\0')
	{
		ft_write(1, &str[i], 1, we);
		if (*we == 1)
			return (-1);
		i++;
	}
	return (i);
}
