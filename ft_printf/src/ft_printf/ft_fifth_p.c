/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fifth_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:06:48 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_putp(char *str, t_printf *el)
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

int		kcehc_complet_charp(char *nbr, char letter, t_printf *el)
{
	int	tmp;
	int count;

	if (ft_strlen(nbr) + 2 < (size_t)(el->width))
	{
		tmp = el->width - ft_strlen(nbr) - 2;
		while (tmp-- > 0)
			ft_putchar(letter);
		count = el->width;
	}
	else
		count = ft_strlen(nbr) + 2;
	return (count);
}

int		with_widthp(char *nbr, t_printf *el)
{
	int count;

	if (el->f_minus)
	{
		ft_putstr("0x");
		ft_putp(nbr, el);
		count = kcehc_complet_charp(nbr, ' ', el);
	}
	else if (el->f_zero)
	{
		ft_putstr("0x");
		count = kcehc_complet_charp(nbr, '0', el);
		ft_putp(nbr, el);
	}
	else
	{
		count = kcehc_complet_charp(nbr, ' ', el);
		ft_putstr("0x");
		ft_putp(nbr, el);
	}
	return (count);
}

int		ft_p(void *address, t_printf *el)
{
	char	*str;
	int		count;

	str = ft_itoabaseu((unsigned long)address, 16, 1);
	if (str[0] == '0' && ft_strlen(str) == 1 && !el->accuracy)
	{
		count = el->width > 0 ? el->width : 0;
		while (el->width-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		return (count + 2);
	}
	if (el->width)
		count = with_widthp(str, el);
	else
	{
		ft_putstr("0x");
		ft_putp(str, el);
		count = ft_strlen(str) + 2;
	}
	if ((el->accuracy != -1) && ((size_t)el->accuracy > ft_strlen(str)))
		count += el->accuracy - ft_strlen(str);
	free(str);
	return (count);
}
