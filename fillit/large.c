/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:51:34 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/18 15:19:44 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		large_ln(t_tetr *tetr)
{
	int	i;
	int large;

	large = 0;
	while (tetr)
	{
		i = 0;
		while (i < 4)
		{
			large = (tetr->body[i].x > large) ? tetr->body[i].x : large;
			large = (tetr->body[i].y > large) ? tetr->body[i].y : large;
			i++;
		}
		tetr = tetr->next;
	}
	return (large + 1);
}

int		large_x(t_tetr *tetr)
{
	int i;
	int large;

	i = 1;
	large = tetr->body[0].x;
	while (i < 4)
	{
		if (tetr->body[i].x > large)
			large = tetr->body[i].x;
		i++;
	}
	return (large);
}

int		large_y(t_tetr *tetr)
{
	int	i;
	int large;

	i = 1;
	large = tetr->body[0].y;
	while (i < 4)
	{
		if (tetr->body[i].y > large)
			large = tetr->body[i].x;
		i++;
	}
	return (large);
}
