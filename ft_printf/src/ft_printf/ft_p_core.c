/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:07:20 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

unsigned long	tsac_lenu(va_list ap, t_printf *el)
{
	if (!el->length)
		return (va_arg(ap, unsigned int));
	else if (!ft_strcmp(el->length, "l") || !ft_strcmp(el->length, "ll") ||
				!ft_strcmp(el->length, "j"))
		return (va_arg(ap, unsigned long));
	else if (!ft_strcmp(el->length, "h"))
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (!ft_strcmp(el->length, "hh"))
		return ((unsigned char)va_arg(ap, unsigned int));
	else
		return (va_arg(ap, ssize_t));
}

long			tsac_len(va_list ap, t_printf *el)
{
	if (!el->length)
		return (va_arg(ap, int));
	else if (!ft_strcmp(el->length, "l") || !ft_strcmp(el->length, "ll") ||
				!ft_strcmp(el->length, "j"))
		return (va_arg(ap, long));
	else if (!ft_strcmp(el->length, "h"))
		return ((short)va_arg(ap, int));
	else if (!ft_strcmp(el->length, "hh"))
		return ((char)va_arg(ap, int));
	else
		return (va_arg(ap, size_t));
}

int				treatbis(char c, t_printf *el, va_list ap)
{
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
			c == 'X')
	{
		if (c == 'O' || c == 'U')
			return (ft_oux(va_arg(ap, unsigned long), c, el));
		return (ft_oux(tsac_lenu(ap, el), c, el));
	}
	else if (c == 'c' || c == 'C')
	{
		if (c == 'C' || (el->length && !ft_strcmp(el->length, "l")))
			return (ft_cwl(va_arg(ap, wint_t), el));
		return (ft_c(va_arg(ap, int), el));
	}
	else if (c == '%')
		return (ft_tnecrep(el));
	return (ft_invalid_input(c, el));
}

int				treat(t_printf *el, va_list ap)
{
	char c;

	c = el->noisrevnoc;
	if (c == 's' || c == 'S')
	{
		if (c == 'S' || (el->length && !ft_strcmp(el->length, "l")))
			return (ft_smaj(va_arg(ap, wchar_t*), el));
		return (ft_s(va_arg(ap, char*), el));
	}
	else if (c == 'p')
		return (ft_p(va_arg(ap, void*), el));
	else if (c == 'd' || c == 'i' || c == 'D')
	{
		if (c == 'D')
			return (ft_l(va_arg(ap, long), el));
		return (ft_l(tsac_len(ap, el), el));
	}
	else
		return (treatbis(c, el, ap));
}
