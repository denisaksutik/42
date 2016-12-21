/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:50:13 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/10 17:35:56 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	char	*ret;

	ret = (char *)s1;
	while (*s1)
		s1++;
	while (len--)
		if (!(*s1++ = *s2++))
			return (ret);
	*s1 = '\0';
	return (ret);
}
