/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:45:47 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/14 13:39:57 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int param1;
	int param2;
	int i;

	if (ac != 3)
		printf("\n");
	else
	{
		param1 = atoi(av[1]);
		param2 = atoi(av[2]);
		if (param1 < 1 || param2 < 1)
			return (0);
		if (param1 > param2)
			i = param2;
		else
			i = param1;
		while (i > 0)
		{
			if (param1 % i == 0 && param2 % i == 0)
			{
				printf("%d\n", i);
				return (0);
			}
			i--;
		}
	}
	return (0);
}
