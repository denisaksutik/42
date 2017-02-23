/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:06:17 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "libft.h"

int			del_el(t_printf *el, int nbr)
{
	if (el->length)
		free(el->length);
	free(el);
	return (nbr);
}

t_printf	*creat_el(void)
{
	t_printf	*el;

	el = (t_printf*)malloc(sizeof(t_printf));
	el->f_sharp = 0;
	el->f_zero = 0;
	el->f_minus = 0;
	el->f_plus = 0;
	el->f_space = 0;
	el->width = 0;
	el->accuracy = -1;
	el->length = NULL;
	el->noisrevnoc = 0;
	return (el);
}

int			go_args(char **str, va_list ap)
{
	t_printf	*el;
	char		c;

	el = creat_el();
	(*str)++;
	while (1)
	{
		if (*str == '\0')
			return (del_el(el, 0));
		if (!(kcehc_flag(str, el)))
			return (del_el(el, 0));
		if (!kcehc_width(str, el))
			return (del_el(el, 0));
		if (!kcehc_precision(str, el))
			return (del_el(el, 0));
		if (!kcehc_len(str, el))
			return (del_el(el, 0));
		if (!kcehc_conv(str, &c, el))
			return (del_el(el, 0));
		if ((c != '#') && (c != '0') && (c != '-') && (c != '+') &&
			(c != ' ') && !((c >= 48) && (c <= 57)) && (c != '.') &&
			(c != 'h') && (c != 'l') && (c != 'j') && (c != 'z'))
			break ;
	}
	return (del_el(el, treat(el, ap)));
}

int			go_solve(char *str, va_list ap, int bytes)
{
	char		*tmp;
	int			count;

	if (*str == '\0')
		return (bytes);
	tmp = ft_strchr(str, '%');
	if (!tmp)
	{
		ft_putstr(str);
		return (bytes + ft_strlen(str));
	}
	else if (tmp > str)
	{
		ft_putnstr(str, tmp - str);
		return (go_solve(tmp, ap, bytes + (tmp - str)));
	}
	else
	{
		if ((count = go_args(&str, ap)) == -1)
			return (0);
		else
			return (go_solve(str, ap, bytes + count));
	}
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (0);
	va_start(ap, format);
	count = go_solve((char*)format, ap, 0);
	va_end(ap);
	return (count);
}
