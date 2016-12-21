/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 20:15:41 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/27 17:03:59 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int issa(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f'
			|| c == '\v' || c == '\0');
}

int main(int ac, char **av)
{
	int i;
	int first;
	int len;

	if (ac > 1)
	{
		first = 0;
		while (issa(av[1][first]) && av[1][first])
			first++;
		len = 0;
		while (!issa(av[1][first + len]))
			len++;
		i = first + len;
		while (av[1][i] != '\0')
		{
			while (issa(av[1][i]) && av[1][i])
				i++;
			if (av[1][i] == '\0')
				break ;
			if (ac == 0)
				write(1, " ", 1);
			ac = 0;
			while (!issa(av[1][i]))
			{
				write(1, av[1] + i++, 1);
			}
		}
		if (len && ac == 0)
			write(1, " ", 1);
		write(1, av[1] + first, len);
	}
	write(1, "\n", 1);
	return (0);
}
