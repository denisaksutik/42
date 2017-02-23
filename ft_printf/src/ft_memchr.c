/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:53:24 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:46 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char*)s;
	while (n--)
	{
		if (*dest == (unsigned char)c)
			return (dest);
		dest++;
	}
	return (NULL);
}
