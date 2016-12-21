/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:30:31 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/01 20:02:16 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void search(char *str, char c, char new)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = new;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][1] == 0 && av[3][1] == 0)
			search(av[1], av[2][0], av[3][0]);
	}
	write(1, "\n", 1);
	return (0);
}

