/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:33:11 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/12 15:31:42 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	a;

	if (c < 0)
		return (-1);
	a = (unsigned char)c;
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return ((int)c);
}
