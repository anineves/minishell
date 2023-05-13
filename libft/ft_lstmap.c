/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:31:48 by mimoreir          #+#    #+#             */
/*   Updated: 2022/11/21 11:31:49 by mimoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newele;

	if (!lst || !f)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		newele = ft_lstnew(f(lst->content));
		if (!newele)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newele, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, newele);
	}
	return (newlst);
}
