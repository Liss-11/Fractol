/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:07:29 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/19 12:44:46 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		j;
	size_t	ln;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		j = 0;
		ln = len + 1;
		while (haystack[j] == needle[j] && needle[j] != '\0'
			&& --ln > 0)
				j++;
		if (needle[j] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
