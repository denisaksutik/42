/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:36:29 by daksiuts          #+#    #+#             */
/*   Updated: 2016/11/24 16:48:03 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_strreverse(char *s)
{
	size_t	i;
	size_t	j;
	char	bfr;

	i = 0;
	j = strlen(s) - 1;
	while (i < j)
	{
		bfr = s[i];
		s[i] = s[j];
		s[j] = bfr;
		j--;
		i++;
	}
}
