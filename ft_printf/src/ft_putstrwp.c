/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrwp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:27:30 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:37:01 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrwp(char *str, int precision)
{
	if ((precision != -1) && ((size_t)precision < ft_strlen(str)))
	{
		while (precision--)
		{
			ft_putchar(*str);
			str++;
		}
	}
	else
		ft_putstr(str);
}
