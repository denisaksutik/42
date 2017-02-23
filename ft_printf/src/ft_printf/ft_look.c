/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:26:47 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		with_width_percent(t_printf *el)
{
	int count;

	count = el->width - 1;
	if (el->f_minus)
	{
		ft_putchar('%');
		while (count-- > 0)
			ft_putchar(' ');
	}
	else if (el->f_zero)
	{
		while (count-- > 0)
			ft_putchar('0');
		ft_putchar('%');
	}
	else
	{
		while (count-- > 0)
			ft_putchar(' ');
		ft_putchar('%');
	}
	return (el->width);
}

int		ft_tnecrep(t_printf *el)
{
	int count;

	count = 0;
	if (el->width)
		count = with_width_percent(el);
	else
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}
