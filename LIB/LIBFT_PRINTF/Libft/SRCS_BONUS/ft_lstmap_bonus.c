/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:38:28 by afrolova          #+#    #+#             */
/*   Updated: 2022/05/27 12:44:37 by afrolova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*m;
	t_list	*new_element;
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		m = f(lst->content);
		new_element = ft_lstnew(m);
		if (!new_element)
		{
			del(m);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
