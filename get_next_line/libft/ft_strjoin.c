/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:52:07 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/11 16:40:00 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	index;

	index = 0;
	if (!s1 || !s2
			|| !(new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
	{
		new[index] = *s1;
		s1 = s1 + 1;
		index++;
	}
	while (*s2)
	{
		new[index] = *s2;
		s2 = s2 + 1;
		index++;
	}
	new[index] = '\0';
	return (new);
}
