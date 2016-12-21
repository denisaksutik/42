/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:23:58 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/13 16:26:45 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
	t_list *list;
	int 	i;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list -> next;
	}
	return (i);
}
