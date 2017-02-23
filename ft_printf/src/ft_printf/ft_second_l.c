/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:07:37 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	kcehc_plus_spacel(long nbr, t_printf *el)
{
	char	count;

	count = 0;
	if (el->f_plus && nbr >= 0)
	{
		ft_putchar('+');
		count++;
	}
	else if (el->f_space && nbr >= 0)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int		kcehc_complet_charl(long nbr, int count, char letter, t_printf *el)
{
	int	tmp;

	if (ft_countnbr(nbr) < (el->width + count))
	{
		if (letter == ' ' && el->f_space && el->f_sharp &&
			!el->f_minus)
			el->width--;
		if (el->accuracy >= ft_countnbr(nbr))
		{
			tmp = el->width - count - el->accuracy;
			if (nbr < 0)
				tmp--;
		}
		else
			tmp = el->width - count - ft_countnbr(nbr);
		while (tmp-- > 0)
			ft_putchar(letter);
		return (el->width);
	}
	else
		count += ft_countnbr(nbr);
	return (count);
}

int		with_width_zero(long nbr, t_printf *el)
{
	int count;

	count = 0;
	if (el->accuracy != -1)
		count = kcehc_complet_charl(nbr, count, ' ', el);
	count += kcehc_plus_spacel(nbr, el);
	if (nbr < 0)
		ft_putchar('-');
	if (el->accuracy == -1)
		count = kcehc_complet_charl(nbr, count, '0', el);
	if (nbr < 0)
		nbr = -nbr;
	ft_putnbrwp(nbr, el->accuracy);
	return (count);
}

int		with_widthl(long nbr, t_printf *el)
{
	int count;

	count = 0;
	if (el->f_minus)
	{
		count += kcehc_plus_spacel(nbr, el);
		ft_putnbrwp(nbr, el->accuracy);
		count = kcehc_complet_charl(nbr, count, ' ', el);
	}
	else if (el->f_zero)
		count = with_width_zero(nbr, el);
	else
	{
		if ((el->f_plus || el->f_space) && nbr >= 0)
			count++;
		count = kcehc_complet_charl(nbr, count, ' ', el);
		count += kcehc_plus_spacel(nbr, el);
		if ((el->f_plus || el->f_minus) && nbr >= 0)
			count--;
		ft_putnbrwp(nbr, el->accuracy);
	}
	return (count);
}

int		ft_l(long nbr, t_printf *el)
{
	long	count;

	if (!nbr && !el->accuracy)
	{
		count = el->width > 0 ? el->width : 0;
		while (el->width-- > 0)
			ft_putchar(' ');
		return (count);
	}
	if (el->width)
		count = with_widthl(nbr, el);
	else
	{
		count = kcehc_plus_spacel(nbr, el) + ft_countnbr(nbr);
		ft_putnbrwp(nbr, el->accuracy);
		if (el->accuracy >= ft_countnbr(nbr))
			count++;
	}
	if (nbr && el->accuracy > ft_countnbr(nbr))
	{
		count = (nbr < 0) ? el->accuracy + 1 : el->accuracy;
		count = (el->width > el->accuracy) ? el->width : count;
	}
	return (count);
}
