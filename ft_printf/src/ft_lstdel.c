/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:06:55 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:05 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	next = *alst;
	while (next)
	{
		tmp = next->next;
		del(next->content, next->content_size);
		free(next);
		next = tmp;
	}
	*alst = NULL;
}
