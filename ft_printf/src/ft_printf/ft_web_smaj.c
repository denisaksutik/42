/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_web_smaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 15:57:20 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>
#include "ft_printf.h"

void	print_wchar(wchar_t *str, int countp)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i] && (countp > j))
	{
		ft_unicode(str[i]);
		j += ft_c_unic(str[i]);
	}
}

int		count_precision(wchar_t *str, t_printf *el)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (str[++i] && ((count + ft_c_unic(str[i])) <= el->accuracy))
		count += ft_c_unic(str[i]);
	return (count);
}

int		w_precision(wchar_t *str, t_printf *el)
{
	int i;
	int	countp;

	i = -1;
	countp = count_precision(str, el);
	if (el->f_minus)
		print_wchar(str, countp);
	if (el->width)
	{
		i = el->width - countp;
		if (el->f_zero)
			while (i-- > 0)
				ft_putchar('0');
		else
			while (i-- > 0)
				ft_putchar(' ');
		i = -1;
	}
	if (!el->f_minus)
		print_wchar(str, countp);
	if (el->width > countp)
		return (el->width);
	return (countp);
}

void	w_width(wchar_t *str, t_printf *el)
{
	int i;
	int count;

	i = -1;
	if (el->f_minus)
		while (str[++i])
			ft_unicode(str[i]);
	count = el->width - ft_c_mult_unic(str);
	if (el->f_zero)
		while (count-- > 0)
			ft_putchar('0');
	else
		while (count-- > 0)
			ft_putchar(' ');
	if (!el->f_minus)
		while (str[++i])
			ft_unicode(str[i]);
}

int		ft_smaj(wchar_t *str, t_printf *el)
{
	int		count;
	int		i;

	if (!str)
		return (is_null(el));
	count = 0;
	i = -1;
	if (el->accuracy != -1)
		return (w_precision(str, el));
	else if (el->width)
		w_width(str, el);
	else
		while (str[++i])
			ft_unicode(str[i]);
	count = ft_c_mult_unic(str);
	if (el->width > count)
		return (el->width);
	return (count);
}
