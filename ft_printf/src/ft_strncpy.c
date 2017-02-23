/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:36:58 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:39:07 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	if (((size_t)ft_strlen((char*)src)) <= n)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
