/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttabstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:55:28 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:37:05 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttabstr(char **str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	ft_putchar('{');
	ft_putchar('\n');
	while (str[i])
	{
		ft_putchar('\t');
		ft_putchar('\"');
		ft_putstr(str[i++]);
		ft_putendl("\",");
	}
	ft_putendl("}");
}
