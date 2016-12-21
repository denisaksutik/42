/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:01:25 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/18 20:33:31 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		file_reader(int a, t_tetr *tetr)
{
	char	*point;
	int		len;
	int		i;

	i = 0;
	point = ft_strnew(21);
	while ((len = read(a, point, 21)) != 0)
	{
		if (len < 20)
			output(3);
		point[len] = '\0';
		if (i)
		{
			tetr->next = tetr_place();
			tetr = tetr->next;
		}
		s_tetr(point, tetr);
		tetr->c = 'A' + i;
		i++;
	}
	return (0);
}

void	s_tetr(char *point, t_tetr *tetr)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (*point)
	{
		if (*point == '#' && x < 4 && y < 4 && i < 4)
			position(tetr, i++, x++, y);
		else if (*point == '.' && x < 4 && y < 4)
			x++;
		else if (*point == '\n' && x == 4 && y < 4)
		{
			y++;
			x = 0;
		}
		else if (*point == '\n' && x == 0 && y == 4)
			y++;
		else
			output(3);
		point++;
	}
}

void	position(t_tetr *tetr, int i, int x, int y)
{
	tetr->body[i].x = x;
	tetr->body[i].y = y;
}
