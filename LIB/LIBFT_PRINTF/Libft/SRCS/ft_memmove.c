/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:07:06 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/11 21:43:31 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (0);
	if (d < s)
	{
		i = -1;
		while (++i < ((int)len))
			d[i] = s[i];
	}
	else
	{
		i = ((int)len - 1);
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}		
	}
	return (dst);
}
