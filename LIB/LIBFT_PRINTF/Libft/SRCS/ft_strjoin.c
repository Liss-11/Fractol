/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:28:17 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/14 14:41:43 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*mall;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	if ((ft_strlen(s1) + ft_strlen(s2)) == 0)
		mall = (char *)malloc(sizeof(char) * 1);
	else
		mall = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (mall == NULL)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i] != '\0')
	{
		mall[i] = s1[i];
		i++;
	}
	while ((i + j) < (ft_strlen(s1) + ft_strlen(s2) + 1)
		&& s2[j] != '\0')
	{
		mall[i + j] = s2[j];
		j++;
	}
	mall[i + j] = '\0';
	return (mall);
}
