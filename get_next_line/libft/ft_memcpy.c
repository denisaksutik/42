/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:29:40 by daksiuts          #+#    #+#             */
/*   Updated: 2017/01/11 20:26:30 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*tmp;
	const char	*s;

	i = 0;
	s = 0;
	tmp = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		tmp[i] = s[i];
		i++;
	}
	return (tmp);
}
