/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:09:29 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/23 23:28:35 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	num_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_free(char *str, char **mall, int len)
{
	if (!str)
	{
		while (len > 0)
		{
			len--;
			free(mall[len]);
		}
		free(mall);
		return (NULL);
	}
	return (str);
}

static char	**full_malloc(char const *s, char c, char **mall)
{
	int				i;
	int				j;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (i == 0 && s[i] != c)
			start = 0;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			end = i;
			mall[j] = ft_substr(s, start, (end - start + 1));
			if (ft_free(mall[j], mall, j) == NULL)
				return (0);
			j++;
		}
		i++;
	}
	mall[j] = NULL;
	return (mall);
}

char	**ft_split(char const *s, char c)
{
	char			**mall;
	int				mall_len;

	mall_len = num_words(s, c);
	mall = (char **)malloc(sizeof(char *) * (mall_len + 1));
	if (mall == 0)
		return (NULL);
	mall = full_malloc(s, c, mall);
	return (mall);
}
