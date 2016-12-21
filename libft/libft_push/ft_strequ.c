/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:09:54 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/16 16:45:21 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2 || *s1 != *s2)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		s1 += 1;
		s2 += 1;
		if (*s1 != *s2)
			return (0);
	}
	return (1);
}