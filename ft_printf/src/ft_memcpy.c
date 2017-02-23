/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:25:44 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:53 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_bis;
	unsigned char	*src_bis;

	dest_bis = dest;
	src_bis = (void*)src;
	while (n--)
		*dest_bis++ = *src_bis++;
	return (dest);
}
