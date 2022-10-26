/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:31:16 by afrolova          #+#    #+#             */
/*   Updated: 2022/10/14 14:59:00 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mall;
	size_t	count;
	size_t	len_src;

	if (!s)
		return (NULL);
	len_src = ft_strlen(s);
	if (len_src < start)
		start = len_src;
	if (len_src - start < len)
		len = len_src - start;
	mall = (char *)malloc_null(sizeof(char) * len);
	if (!mall)
		return (NULL);
	count = 0;
	while (start + count < len_src && count < len)
	{
		mall[count] = s[start + count];
		count++;
	}
	mall[count] = '\0';
	return (mall);
}
