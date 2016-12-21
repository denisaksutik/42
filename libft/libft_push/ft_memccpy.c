/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:49:08 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/10 17:33:50 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		ch;
	char		*tmp;
	const char	*s;

	s = 0;
	tmp = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		ch = *s++;
		*tmp++ = ch;
		if (ch == (char)c)
			return (tmp);
	}
	return (NULL);
}
