/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:02:42 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/11 18:07:32 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src[i] == '\0')
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
