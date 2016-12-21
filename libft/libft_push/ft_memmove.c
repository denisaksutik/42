/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:02:12 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/10 17:34:10 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	tmp = (char *)dst;
	s = (char *)src;
	if (src == dst)
		return (dst);
	if (src > dst)
	{
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += len - 1;
		s += len - 1;
		while (len--)
			*tmp-- = *s--;
	}
	return (dst);
}
