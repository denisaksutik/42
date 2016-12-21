/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:49:27 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/10 17:36:41 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*cp;
	char	*s1;
	char	*s2;

	cp = (char *)big;
	if (!*little)
		return ((char *)big);
	while (*cp)
	{
		s1 = cp;
		s2 = (char *)little;
		while (*s1 && *s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return (cp);
		cp++;
	}
	return (NULL);
}
