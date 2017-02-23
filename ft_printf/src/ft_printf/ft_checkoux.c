/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkoux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:06:38 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		end_o(char *str, int count, t_printf *el)
{
	if (el->accuracy != -1 && (size_t)el->accuracy > ft_strlen(str))
		count += el->accuracy - ft_strlen(str);
	if (el->f_sharp && str[0] != '0' &&
		el->accuracy < (int)ft_strlen(str))
		count++;
	if ((size_t)el->width > ft_strlen(str) &&
		el->accuracy < el->width)
		count = el->width;
	return (count);
}

int		kcehc_complet_charu(unsigned long nbr, int i, char l, t_printf *el)
{
	int	tmp;

	if (ft_countunbr(nbr) < (el->width + i))
	{
		if (el->accuracy > ft_countunbr(nbr))
			tmp = el->width - i - el->accuracy;
		else
			tmp = el->width - i - ft_countunbr(nbr);
		while (tmp-- > 0)
			ft_putchar(l);
		i = el->width;
	}
	else
		i += ft_countunbr(nbr);
	return (i);
}

int		with_u(unsigned long nbr, t_printf *el)
{
	int count;

	count = 0;
	if (el->f_minus)
	{
		ft_putunbrwp(nbr, el->accuracy);
		count = kcehc_complet_charu(nbr, count, ' ', el);
	}
	else if (el->f_zero)
	{
		count = kcehc_complet_charu(nbr, count, '0', el);
		ft_putunbrwp(nbr, el->accuracy);
	}
	else
	{
		count += kcehc_complet_charu(nbr, count, ' ', el);
		ft_putunbrwp(nbr, el->accuracy);
	}
	return (count);
}

int		ft_u(unsigned long nbr, t_printf *el)
{
	int count;

	count = 0;
	if (!el->accuracy && !nbr)
		return (0);
	if (el->width)
		count = with_u(nbr, el);
	else
	{
		count = ft_countunbr(nbr);
		ft_putunbrwp(nbr, el->accuracy);
		if (el->accuracy >= ft_countunbr(nbr))
			count++;
	}
	if (el->accuracy > ft_countunbr(nbr))
	{
		if (el->width > el->accuracy)
			count = el->width;
		else
			count = el->accuracy;
	}
	return (count);
}

int		ft_oux(unsigned long nbr, char letter, t_printf *el)
{
	if (letter == 'o' || letter == 'O')
		return (ft_o(nbr, el));
	else if (letter == 'u' || letter == 'U')
		return (ft_u(nbr, el));
	else
		return (ft_x(nbr, letter, el));
	return (0);
}
