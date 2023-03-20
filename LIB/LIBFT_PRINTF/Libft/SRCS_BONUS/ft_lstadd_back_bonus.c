/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:59:36 by afrolova          #+#    #+#             */
/*   Updated: 2022/08/15 18:39:50 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*my;

	if (!lst)
		return ;
	if (*lst != NULL)
	{
		my = *lst;
		while (my->next != NULL)
			my = my->next;
		my->next = new;
	}
	else
		*lst = new;
}
