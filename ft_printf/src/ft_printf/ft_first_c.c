/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:41:32 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:26:14 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf.h"
#include "libft.h"

int		ft_c_unic(wchar_t c)
{
	if ((c >> 16) != 0)
		return (4);
	else if ((c >> 11) != 0)
		return (3);
	else if ((c >> 7) != 0)
		return (2);
	else
		return (1);
}

int		ft_c_mult_unic(wchar_t *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
		count += ft_c_unic(str[i]);
	return (count);
}

void	ft_unicode(unsigned int c)
{
	if ((c >> 16) != 0)
		four_bytes(c);
	else if ((c >> 11) != 0)
		three_bytes(c);
	else if ((c >> 7) != 0)
		two_bytes(c);
	else
		ft_putchar(c);
}

int		ft_cwl(wint_t c, t_printf *el)
{
	int count;

	if (el->width)
	{
		if (ft_c_unic(c) > 1)
			count = el->width - ft_c_unic(c);
		else
			count = el->width - 1;
		if (el->f_minus)
			ft_unicode(c);
		while (count-- > 0)
			ft_putchar(' ');
		if (!el->f_minus)
			ft_unicode(c);
	}
	else
		ft_unicode(c);
	count = ft_c_unic(c);
	if (el->width > count)
		return (el->width);
	return (count);
}

int		ft_c(int c, t_printf *el)
{
	int				count;
	unsigned char	cha;

	count = 0;
	cha = c & 255;
	if (el->width)
	{
		count = el->width;
		if (el->f_minus)
			ft_putchar(cha);
		if (el->f_zero)
			while (--count)
				ft_putchar('0');
		else
			while (--count)
				ft_putchar(' ');
		if (!el->f_minus)
			ft_putchar(cha);
		return (el->width);
	}
	ft_putchar(cha);
	return (1);
}
