/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:11:59 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/18 22:35:00 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tetr		*tetr;
	int			a;
	char		**map;

	if (ac != 2)
		output(0);
	tetr = tetr_place();
	if ((a = open(av[1], O_RDONLY)) == -1)
		output(2);
	file_reader(a, tetr);
	b_tetr(tetr);
	testing(tetr);
	map = solution_tetr(tetr);
	map_print(map);
	return (0);
}

t_tetr		*tetr_place(void)
{
	t_tetr	*tetr;

	if (!(tetr = (t_tetr *)malloc(sizeof(t_tetr))))
		output(1);
	tetr->pos.x = 0;
	tetr->pos.y = 0;
	tetr->next = NULL;
	return (tetr);
}

void		map_print(char **dot)
{
	int			x;
	int			y;

	y = 0;
	while (dot[y])
	{
		x = 0;
		while (dot[y][x])
		{
			write(1, &dot[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int			output(int code)
{
	if (code == 0)
		write(1, "usage: ./fillit \"filename\"\n", 27);
	else
		write(1, "error\n", 6);
	exit(1);
}
