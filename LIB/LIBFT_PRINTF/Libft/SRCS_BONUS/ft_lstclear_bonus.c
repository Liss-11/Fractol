/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:44:16 by afrolova          #+#    #+#             */
/*   Updated: 2022/06/06 16:25:46 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*my;
	t_list	*m;

	if (!lst)
		return ;
	if (*lst != NULL)
	{	
		my = *lst;
		while (my != NULL)
		{
			del(my->content);
			m = my->next;
			free(my);
			my = m;
		}
		*lst = NULL;
	}
}
