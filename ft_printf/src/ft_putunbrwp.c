/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrwp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:38:13 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/16 16:37:15 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbrwp(unsigned long nbr, int precision)
{
	short count;

	if (precision > 0)
	{
		count = ft_countnbr(nbr);
		count = precision - count;
		while (count-- > 0)
			ft_putchar('0');
	}
	if (nbr || precision)
		ft_putunbr(nbr);
}
