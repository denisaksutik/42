/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_six_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:07:52 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		is_normal(char *str, t_printf *el)
{
	int count;
	int size;

	if (el->f_minus)
		ft_putstrwp(str, el->accuracy);
	if ((el->accuracy != -1) && (size_t)el->accuracy < ft_strlen(str))
		size = el->accuracy;
	else
		size = ft_strlen(str);
	count = size;
	if (el->width > size)
		count = el->width;
	if (el->f_zero && !el->f_minus)
		while (el->width-- > size)
			ft_putchar('0');
	else
		while (el->width-- > size)
			ft_putchar(' ');
	if (!el->f_minus)
		ft_putstrwp(str, el->accuracy);
	return (count);
}

int		is_null(t_printf *el)
{
	int	size;

	size = 0;
	if (el->f_minus)
		ft_putstrwp("(null)", el->accuracy);
	if (el->width > 6 || (el->width > el->accuracy &&
		el->accuracy != -1))
	{
		size += el->width;
		if ((el->accuracy != -1) && el->accuracy < 6)
			size += 6 - el->accuracy;
		while (size-- > 6)
			ft_putchar('0');
	}
	if (!el->f_minus)
		ft_putstrwp("(null)", el->accuracy);
	if (el->width > 6 || (el->width > el->accuracy &&
		el->accuracy != -1))
		return (el->width);
	if ((el->accuracy != -1) && (el->accuracy < 6))
		return (el->accuracy);
	return (6);
}

int		ft_s(char *str, t_printf *el)
{
	int		count;

	count = 0;
	if (!str)
		return (is_null(el));
	else if ((size_t)el->width > ft_strlen(str) ||
			(el->width > el->accuracy))
		count = is_normal(str, el);
	else
	{
		ft_putstrwp(str, el->accuracy);
		if ((el->accuracy != -1) && (size_t)el->accuracy < ft_strlen(str))
			count += el->accuracy;
		else
			count += ft_strlen(str);
	}
	return (count);
}
