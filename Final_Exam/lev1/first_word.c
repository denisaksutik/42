/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:01:15 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/01 16:42:21 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void first_word(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
				|| str[i] == '\v' || str[i] == '\n')
			break ;
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
		first_word(av[1]);
		ft_putchar('\n');
	}
	return (0);
}
