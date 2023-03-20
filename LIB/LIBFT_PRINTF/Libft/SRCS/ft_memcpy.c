/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:06:35 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/20 15:32:10 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	char		*i;
	char		*a;
	size_t		z;

	i = (char *)dst;
	a = (char *)src;
	z = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	while (z < n)
	{
		i[z] = a[z];
		z++;
	}	
	return (dst);
}
