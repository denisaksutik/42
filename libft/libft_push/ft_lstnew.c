/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:57:01 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/23 15:54:18 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list_new;

	if (!(list_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list_new->next = NULL;
	if (content != NULL && content_size != 0)
	{
		list_new->content = malloc(content_size);
		if ((list_new->content) == NULL)
			return (NULL);
		ft_memcpy(list_new->content, content, content_size);
		list_new->content_size = content_size;
	}
	else
	{
		list_new->content = NULL;
		list_new->content_size = 0;
	}
	return (list_new);
}
