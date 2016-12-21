/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:58:24 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/01 18:26:16 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rev_print(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i = i - 1;
	while (str[i])
	{
		ft_putchar(str[i]);
		i--;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
	}
	else 
	{
		rev_print(av[1]);
		ft_putchar('\n');
	}
	return (0);
}
