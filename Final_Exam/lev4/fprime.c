/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:31:10 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/04 12:44:29 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void ft_prime(char *str)
{
	int nb;
	int div;

	div = 2;
	nb = atoi(str);
	if (nb == 1)
		printf("1");
	if (nb < 1)
		return ;
	while (div <= nb)
	{
		if (nb % div == 0)
		{
			printf("%d", div);
			if (nb == div)
				return ;
			printf("*");
			nb = nb / div;
			div = 1;
		}
		div++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_prime(av[1]);
	printf("\n");
	return (0);
}
