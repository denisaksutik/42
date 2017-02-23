/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourth_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:35:37 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:16:19 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_p_o(char *str, t_printf *el)
{
	int i;

	if ((el->accuracy != -1) && ((size_t)el->accuracy > ft_strlen(str)))
	{
		i = el->accuracy - ft_strlen(str);
		while (i--)
			ft_putchar('0');
	}
	ft_putstr(str);
}

int		kcehc_complet_charo(char *nbr, char letter, t_printf *el)
{
	int	tmp;
	int count;

	if (ft_strlen(nbr) < (size_t)(el->width))
	{
		if ((el->accuracy != -1) &&
			((size_t)el->accuracy > ft_strlen(nbr)))
			tmp = el->width - el->accuracy;
		else
			tmp = el->width - ft_strlen(nbr);
		if (el->f_sharp)
			tmp--;
		while (tmp-- > 0)
			ft_putchar(letter);
		if (el->accuracy < el->width)
			count = el->width;
		else
			count = ft_strlen(nbr);
	}
	else
		count = ft_strlen(nbr);
	return (count);
}

void	putzero_ifsharp(char *nbr, t_printf *el)
{
	if (el->f_sharp && !(ft_strlen(nbr) == 1 && nbr[0] == '0') &&
		el->accuracy < (int)ft_strlen(nbr))
		ft_putchar('0');
}

int		with_widtho(char *nbr, t_printf *el)
{
	int count;

	if (el->f_minus)
	{
		putzero_ifsharp(nbr, el);
		ft_p_o(nbr, el);
		count = kcehc_complet_charo(nbr, ' ', el);
	}
	else if (el->f_zero)
	{
		count = kcehc_complet_charo(nbr, '0', el);
		putzero_ifsharp(nbr, el);
		ft_p_o(nbr, el);
	}
	else
	{
		count = kcehc_complet_charo(nbr, ' ', el);
		putzero_ifsharp(nbr, el);
		ft_p_o(nbr, el);
	}
	return (count);
}

int		ft_o(unsigned long nbr, t_printf *el)
{
	char	*str;
	int		count;

	if (!nbr && !el->accuracy && !el->f_sharp)
	{
		count = el->width > 0 ? el->width : 0;
		while (el->width-- > 0)
			ft_putchar(' ');
		return (count);
	}
	str = ft_itoabaseu(nbr, 8, 0);
	if (el->width)
		count = with_widtho(str, el);
	else
	{
		putzero_ifsharp(str, el);
		ft_p_o(str, el);
		count = ft_strlen(str);
	}
	count = end_o(str, count, el);
	free(str);
	return (count);
}
