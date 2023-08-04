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
	if (c < 0)
		return (-1);
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
	{
		c = c - 32;
	}
	return ((int)c);
}
