/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 01:18:30 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:39:25 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*out;

	out = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			out = ((char*)&s[i]);
		i++;
	}
	if (c == '\0')
		out = ((char*)&s[i]);
	return (out);
}
