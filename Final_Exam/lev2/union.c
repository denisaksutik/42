/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:19:00 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/04 16:35:57 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_cmp(char *str, char c, char index)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (i == index)
		write(1, &str[i], 1);
}

void ft_union(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		ft_cmp(s1, s1[i], i);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s2[i] == s1[j])
				break ;
			j++;
		}
		if (s1[j] == '\0')
			ft_cmp(s2, s2[i], i);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
