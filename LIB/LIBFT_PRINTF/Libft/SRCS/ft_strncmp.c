/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:37:33 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/12 21:01:59 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	diff(unsigned char s1, unsigned char s2)
{
	if (s1 > s2)
		return (1);
	else
		return (-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i <= (n - 1))
	{
		if (s1[i] != s2[i])
			return (diff(s1[i], s2[i]));
		i++;
	}
	return (0);
}
