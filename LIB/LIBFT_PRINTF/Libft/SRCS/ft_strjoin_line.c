/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:42:07 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/14 14:55:30 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*mall;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	if (!s1)
	{
		s1 = malloc_null(0);
		if (!s1)
			return (NULL);
	}
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	mall = malloc_null(size_s1 + size_s2 + 1);
	if (!mall)
		return (NULL);
	while (i++ < size_s1)
		mall[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < size_s2)
		mall[size_s1 + i - 1] = s2[i - 1];
	mall[size_s1 + i - 1] = '\0';
	free(s1);
	return (mall);
}
