/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:43:56 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/13 14:03:37 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 0;
	while ((str[i]) && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
				|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-nb);
	else
		return (nb);
}

void ft_putnbr(int nbr)
{
	char c;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

int ft_is_prim(int nbr)
{
	int i;

	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_add_prim_sum(int nbr)
{
	int i;
	int count;

	i = 2;
	count = 0;
	while (i <= nbr)
	{
		if (ft_is_prim(i))
			count = count + i;
		i++;
	}
	ft_putnbr(count);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_add_prim_sum(ft_atoi(av[1]));
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
}
