/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:32:14 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/03 20:26:12 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	ncopy;

	s = NULL;
	ncopy = (long)n;
	len = ft_intlen(ncopy);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	len--;
	if (n < 0)
	{
		s[0] = '-';
		ncopy = -ncopy;
	}
	while (len > 0)
	{
		s[len] = ncopy % 10 + '0';
		ncopy = ncopy / 10;
		len--;
	}
	if (n >= 0)
		s[len] = ncopy % 10 + '0';
	return (s);
}
