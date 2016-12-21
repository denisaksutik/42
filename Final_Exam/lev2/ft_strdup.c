/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:02:31 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/03 18:40:22 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	int i;
	char *dst;

	i = 0;
	if (src == '\0')
		return (NULL);
	while (src[i])
		i++;

	dst = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int main(void)
{
	char src[] = "monday123";

	printf("%s\n", ft_strdup(src));
	printf("%s\n", strdup(src));

	return (0);
}
