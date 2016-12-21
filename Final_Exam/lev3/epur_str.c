/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:49:36 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/13 16:09:21 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	char *str;

	if (ac == 2)
	{
		i = -1;
		str = av[1];
		while (*str != '\0')
		{
			while (*str == ' ' || *str == '\t')															str++;
			if (i != -1 && *str != '\0')
				write(1, " ", 1);
			i = 0;
			while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
				i++;
			write(1, str, i);
			str += i;																				}
	}
	write(1, "\n", 1);
	return (0);
}
