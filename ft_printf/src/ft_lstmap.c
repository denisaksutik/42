/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:40:29 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:23 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*new;
	t_list	*tmp;

	new = f(lst);
	if ((result = ft_lstnew(new->content, new->content_size)))
	{
		tmp = result;
		lst = lst->next;
		while (lst)
		{
			new = f(lst);
			if (!(tmp->next = ft_lstnew(new->content, new->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (result);
}
