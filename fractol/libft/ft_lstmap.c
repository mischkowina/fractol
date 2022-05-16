/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:10:23 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 14:10:04 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates through lst and applies the function f to the content of each element,
creating a new list resulting of the successive application of f.
del is used to delete the content of an element if necessary.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((lst->content));
	if (!new)
		return (NULL);
	tmp = new;
	while (lst)
	{
		new->content = (*f)(new->content);
		if (!new->content)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		lst = lst->next;
		if (!lst)
			break ;
		new->next = ft_lstnew(lst->content);
		new = new->next;
	}
	new->next = NULL;
	return (tmp);
}
