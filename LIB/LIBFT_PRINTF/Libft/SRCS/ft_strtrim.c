/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:20:40 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/19 22:54:46 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mall;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 && !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	mall = ft_substr(s1, start, end - start + 1);
	if (!mall)
		return (NULL);
	return (mall);
}
