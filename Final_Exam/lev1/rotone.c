/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:53:10 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/03 12:48:46 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rotone(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] < 'z')
			ft_putchar(str[i] + 1);
		else if (str[i] >= 'A' && str[i] > 'Z')
			ft_putchar(str[i] + 1);
		else if (str[i] == 'z' || str[i] == 'Z')
			ft_putchar(str[i] - 25);
		else
			ft_putchar(str[i]);
		i++;
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
		rotone(av[1]);
		ft_putchar('\n');
	}
	return (0);
}
