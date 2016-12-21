/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidenp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:03:32 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/13 17:31:12 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (ac == 3)
	{
		while (av[1][a] && av[2][b])
		{
			if (av[1][a] == av[2][b])
				a++;
			b++;
		}
		if (av[1][a] == '\0')
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
	return (0);
}
