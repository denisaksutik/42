/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:08:42 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/24 00:18:40 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (size >= 0x7fff7d52d000)
		return (NULL);
	if (!(mem = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
