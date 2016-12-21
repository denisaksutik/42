/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:36:18 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/18 21:54:29 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		square_min(t_tetr *tetr)
{
	float	x;
	float	y;
	float	count;

	y = 1;
	count = 0;
	while (tetr)
	{
		count++;
		tetr = tetr->next;
	}
	count *= 4;
	x = count;
	while (x - y > 0.000001)
	{
		x = (x + y) / 2;
		y = count / x;
	}
	return ((int)(x + 0.99));
}

void	clean_tetr(t_tetr *tetr, char **dot)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		dot[tetr->body[i].y + tetr->pos.y][tetr->body[i].x +
			tetr->pos.x] = '.';
		i++;
	}
}

char	**g_new_map(int size)
{
	int		i;
	int		j;
	char	**n_map;

	i = 0;
	if (!(n_map = (char **)malloc(sizeof(char *) * (size + 1))))
		output(1);
	n_map[size] = NULL;
	while (i < size)
	{
		if (!(n_map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			output(1);
		j = 0;
		while (j < size)
		{
			n_map[i][j] = '.';
			j++;
		}
		n_map[i][j] = '\0';
		i++;
	}
	return (n_map);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (str);
}

void	map_free(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
