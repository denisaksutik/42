/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:39:02 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/23 22:35:37 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;

	newlist = NULL;
	if (!lst)
		return (NULL);
	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	while (newlist)
	{
		newlist = f(lst);
		newlist->next = ft_lstmap(lst->next, f);
		return (newlist);
	}
	return (NULL);
}
