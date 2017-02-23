/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:12:27 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:39:48 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;
	int		size;

	i = -1;
	size = ft_strlen((char*)s);
	if (!s || ((size - start) < len))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (start--)
		s++;
	while (len--)
	{
		str[++i] = *s;
		s++;
	}
	str[++i] = '\0';
	return (str);
}
