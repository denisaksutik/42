/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:09:53 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/14 11:39:32 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *tab;
	int i;

	i = 0;
	if (start >= end)
		return (NULL);
	tab = (int *)malloc(sizeof(*tab) * (end - start));
	while (start < end)
	{
		tab[i] = start;
		i++;
		start++;
	}	
	return (tab);
}
