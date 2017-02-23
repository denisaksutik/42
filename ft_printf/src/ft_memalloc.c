/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:59:59 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:35:33 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (size))))
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}
