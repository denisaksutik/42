/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:01:08 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/01 17:24:01 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void repeat_alpha(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			j = str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			j = str[i] - 'A';
		else
			j = 0;
		while (j >= 0)
		{
			ft_putchar(str[i]);
			j--;
		}
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
		repeat_alpha(av[1]);
		ft_putchar('\n');
	}
	return (0);
}
