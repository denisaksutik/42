/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:11:18 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/03 20:29:01 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_intlen(int nb)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nb)
{
	char *s;
	size_t len;
	long nbcopy;

	s = NULL;
	nbcopy = (long)nb;
	len =  ft_intlen(nbcopy);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	len--;
	if (nb < 0)
	{
		s[0] = '-';
		nbcopy = -nbcopy;
	}
	while (len > 0)
	{
		s[len] = nbcopy % 10 + '0';
		nbcopy = nbcopy / 10;
		len--;
	}
	if (nb >= 0)
		s[len] = nbcopy % 10 +'0';
	return (s);
}
