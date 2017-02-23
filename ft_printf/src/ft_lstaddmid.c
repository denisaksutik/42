/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddmid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:32:11 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:34:54 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddmid(t_list **alst, t_list *previous, t_list *new)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!alst || !previous || !new)
		return ;
	tmp = *alst;
	while (tmp && (tmp != previous))
		tmp = tmp->next;
	if (tmp == previous)
	{
		tmp2 = tmp->next;
		tmp->next = new;
		new->next = tmp2;
	}
}
