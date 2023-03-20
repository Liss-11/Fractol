/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:56:07 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/12 19:56:47 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	a;

	if (c < 0)
		return (-1);
	a = (unsigned char)c;
	if (a >= 'A' && a <= 'Z')
		a = a + 32;
	return ((int)a);
}
