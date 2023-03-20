/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:44:07 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/19 15:44:57 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mall;
	size_t	i;

	i = 0;
	mall = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mall == 0)
		return (NULL);
	while (i < ft_strlen(s))
	{
		mall[i] = f(i, s[i]);
		i++;
	}
	mall[i] = '\0';
	return (mall);
}
