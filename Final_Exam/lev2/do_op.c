/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:15:39 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/02 16:38:55 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int result;

	result = 0;
	if (ac == 4)
	{
		if (av[2][0] == '*')
			result = atoi(av[1]) * atoi(av[3]);
		else if (av[2][0] == '-')
			result = atoi(av[1]) - atoi(av[3]);
		else if (av[2][0] == '+')
			result = atoi(av[1]) + atoi(av[3]);
		else if (av[2][0] == '/')
			result = atoi(av[1]) / atoi(av[3]);
		else if (av[2][0] == '%')
			result = atoi(av[1]) % atoi(av[3]);
		printf("%i\n", result);
	}
	else
		write (1, "\n", 1);
	return (0);
}
