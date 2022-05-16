/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:42:54 by smischni          #+#    #+#             */
/*   Updated: 2022/01/10 14:05:27 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Deletes and frees the given element and every successor, using the function
del and free. Finally, the pointer to the list is set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*t;

	if (!lst || !del || !*lst)
		return ;
	while (*lst && lst)
	{
		t = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = t;
	}
	*lst = NULL;
}
