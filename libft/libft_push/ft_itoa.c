/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:32:12 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/24 11:38:56 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
