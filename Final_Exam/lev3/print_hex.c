/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:34:30 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/14 14:44:04 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int power(int nb)
{
	int power;

	power = 16;
	while (power < nb)
		power = power * 16;
	if (power > nb)
		power = power / 16;
	return (power);
}

void ft_print_hex(int nb)
{
	int pwr;
	int index;
	int rest;
	char *hex;

	hex = "0123456789abcdef";
	pwr = power(nb);
	while (pwr > 0)
	{
		index = nb / pwr;
		rest = nb % pwr;
		write(1, &hex[index], 1);
		pwr = pwr / 16;
		nb = rest;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_print_hex(av[1]);
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}

