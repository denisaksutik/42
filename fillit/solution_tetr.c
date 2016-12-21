/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_tetr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 13:37:14 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/18 16:35:59 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**solution_tetr(t_tetr *tetr)
{
	int		small;
	int		large;
	char	**map;

	large = large_ln(tetr);
	small = square_min(tetr);
	small = (large > small) ? large : small;
	map = g_new_map(small);
	while (next_s(tetr, small, map) != 1)
	{
		small++;
		tetr->next->pos.x = 0;
		tetr->next->pos.y = 0;
		map_free(map);
		map = g_new_map(small);
	}
	return (map);
}

int		write_tetr(t_tetr *q, char **c, int small)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (q->body[i].x + q->pos.x >= small)
			break ;
		if (q->body[i].y + q->pos.y >= small)
			break ;
		if (c[q->body[i].y + q->pos.y][q->body[i].x + q->pos.x] != '.')
			break ;
		i++;
	}
	if (i == 4)
	{
		i = 0;
		while (i < 4)
		{
			c[q->body[i].y + q->pos.y][q->body[i].x + q->pos.x] = q->c;
			i++;
		}
		return (1);
	}
	return (0);
}

int		next_s(t_tetr *tetr, int small, char **map)
{
	while (tetr)
	{
		while (write_tetr(tetr, map, small) != 1)
			if (move_tetr(small, tetr) == -1)
				return (-1);
		if (next_s(tetr->next, small, map) == 1)
			return (1);
		clean_tetr(tetr, map);
		if (move_tetr(small, tetr) == -1)
			return (-1);
	}
	return (1);
}

int		move_tetr(int small, t_tetr *tetr)
{
	tetr->pos.x++;
	if (tetr->pos.x == small)
	{
		tetr->pos.y++;
		tetr->pos.x = 0;
	}
	if (tetr->pos.y + large_y(tetr) > small)
	{
		tetr->pos.x = 0;
		tetr->pos.y = 0;
		return (-1);
	}
	return (1);
}
