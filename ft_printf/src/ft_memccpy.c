/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:41:13 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:40 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_bis;
	const unsigned char	*src_bis;

	dest_bis = dest;
	src_bis = (void*)src;
	while (n--)
	{
		if ((*dest_bis++ = *src_bis++) == (unsigned char)c)
			return (dest_bis);
	}
	return (NULL);
}
