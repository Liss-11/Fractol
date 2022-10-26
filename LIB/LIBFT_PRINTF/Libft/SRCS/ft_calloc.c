/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:56:56 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/16 22:12:33 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mall;
	size_t	i;

	i = count * size;
	mall = (char *)malloc(i);
	if (mall != NULL)
	{
		ft_bzero(mall, i);
		return (mall);
	}
	return (NULL);
}
