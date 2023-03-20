/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:35:30 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/17 22:13:44 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*mall;
	size_t		i;

	i = 0;
	len = ft_strlen(s1);
	mall = (char *)malloc(len + 1);
	if (mall != NULL)
	{
		while (i < len)
		{
			mall[i] = s1[i];
			i++;
		}
		mall[i] = '\0';
		return (mall);
	}
	return (NULL);
}
