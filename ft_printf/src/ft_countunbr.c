/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:39:48 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:25:23 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

short	ft_countunbr(unsigned long nbr)
{
	short count;

	if (!nbr)
		return (1);
	count = 0;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
