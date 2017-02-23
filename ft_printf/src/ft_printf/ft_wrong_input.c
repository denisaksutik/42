/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrong_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:35:37 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:23:29 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		with_width_invalid(char c, t_printf *el)
{
	int	count;

	count = el->width - 1;
	if (el->f_minus)
	{
		ft_putchar(c);
		while (count-- > 0)
			ft_putchar(' ');
	}
	else if (el->f_zero)
	{
		while (count-- > 0)
			ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		while (count-- > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (el->width);
}

int		ft_invalid_input(char c, t_printf *el)
{
	int		count;

	count = 1;
	if (el->width)
		count = with_width_invalid(c, el);
	else
		ft_putchar(c);
	return (count);
}
