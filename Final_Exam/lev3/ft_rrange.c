/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:37:17 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/13 16:49:12 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int *ft_range_first(int start, int end)
{
	int *tab;
	int i;

	i = 0;
	while ((start + i) <= end)
		i++;
	if (!(tab = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	i = -1;
	while ((start + ++i) <= end)
		tab[i] = start + i;
	return (tab);
}

int *ft_range_second(int start, int end)
{
	int	*tab;
	int i;

	i = 0;
	while ((start + i) <= end)
		i++;
	if (!(tab = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	i = -1;
	while ((end - ++i) >= start)
		tab[i] = end - i;
	return (tab);
}

int     *ft_rrange(int start, int end)
{
	if (start < end)
		return (ft_range_first(start, end));
	return (ft_range_second(end, start));
}
