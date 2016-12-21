/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:18:05 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/11 16:18:13 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	index;

	index = 0;
	if (!s || !f
			|| !(new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[index])
	{
		new_str[index] = (*f)(s[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
