/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:46:55 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:27 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content = malloc(sizeof(*content) * content_size);
			if (!(new->content))
			{
				free(new);
				return (NULL);
			}
			ft_memcpy((new->content), content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
	}
	return (new);
}
