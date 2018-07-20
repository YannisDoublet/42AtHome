/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:20:08 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 15:45:59 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;
	t_list	*tmp;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	lst = lst->next;
	first = new;
	while (lst)
	{
		tmp = (*f)(lst);
		new->next = tmp;
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
