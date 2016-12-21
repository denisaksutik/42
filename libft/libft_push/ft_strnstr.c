/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:37:16 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/23 23:11:22 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (small[0] == '\0')
		return ((char *)big);
	while ((i < len) && big[i])
	{
		if (big[i] == *small)
		{
			n = 0;
			while ((big[i + n] == small[n]) && (i + n < len))
			{
				n++;
				if (!small[n])
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
