/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:21:47 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/26 20:10:05 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{	
	t_list	*str;

	str = (t_list *)malloc(sizeof(t_list) * 1);
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
