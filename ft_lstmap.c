#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	if (lst && f)
	{
		ft_lstmap(lst->next, f);
		(*f)(lst);
		return(ft_lstnew(lst->content, lst->content_size));
	}
	return (NULL);
}
