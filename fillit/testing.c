/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:21:18 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/18 15:19:32 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	b_tetr(t_tetr *tetr)
{
	int small_x;
	int small_y;
	int	i;

	while (tetr)
	{
		small_x = tetr->body[0].x;
		small_y = tetr->body[0].y;
		i = 1;
		while (i < 4)
		{
			small_x = (tetr->body[i].x < small_x) ? tetr->body[i].x : small_x;
			small_y = (tetr->body[i].y < small_y) ? tetr->body[i].y : small_y;
			i++;
		}
		i = 0;
		while (i < 4)
		{
			tetr->body[i].x -= small_x;
			tetr->body[i].y -= small_y;
			i++;
		}
		tetr = tetr->next;
	}
}

int		compare_tetr(t_tetr *tetr)
{
	int i;

	i = 0;
	while (i < 19)
	{
		if (tetr->body[0].x == g_tetr[i][0].x &&
			tetr->body[1].x == g_tetr[i][1].x &&
			tetr->body[2].x == g_tetr[i][2].x &&
			tetr->body[3].x == g_tetr[i][3].x &&
			tetr->body[0].y == g_tetr[i][0].y &&
			tetr->body[1].y == g_tetr[i][1].y &&
			tetr->body[2].y == g_tetr[i][2].y &&
			tetr->body[3].y == g_tetr[i][3].y)
			return (0);
		i++;
	}
	return (-1);
}

void	testing(t_tetr *tetr)
{
	while (tetr)
	{
		if (compare_tetr(tetr) == -1)
			output(3);
		tetr = tetr->next;
	}
}
