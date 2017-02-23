/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seven_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:07:44 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_putx(char *str, t_printf *el)
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

int		kcehc_complet_charx(char *nbr, char letter, t_printf *el)
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
			tmp -= 2;
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

int		with_widthx(char *nbr, char letter, t_printf *el)
{
	int count;

	if (el->f_minus)
	{
		if (el->f_sharp && !(ft_strlen(nbr) == 1 && nbr[0] == '0'))
			ft_putzerox(letter);
		ft_putx(nbr, el);
		count = kcehc_complet_charx(nbr, ' ', el);
	}
	else if (el->f_zero)
	{
		if (el->f_sharp && !(ft_strlen(nbr) == 1 && nbr[0] == '0'))
			ft_putzerox(letter);
		count = kcehc_complet_charx(nbr, '0', el);
		ft_putx(nbr, el);
	}
	else
	{
		count = kcehc_complet_charx(nbr, ' ', el);
		if (el->f_sharp && !(ft_strlen(nbr) == 1 && nbr[0] == '0'))
			ft_putzerox(letter);
		ft_putx(nbr, el);
	}
	return (count);
}

int		without_width(char *str, char letter, t_printf *el)
{
	if (el->f_sharp && !(ft_strlen(str) == 1 && str[0] == '0'))
		ft_putzerox(letter);
	ft_putx(str, el);
	return (ft_strlen(str));
}

int		ft_x(unsigned long nbr, char letter, t_printf *el)
{
	char	*str;
	int		count;

	if (!nbr && !el->accuracy)
	{
		count = el->width;
		while (el->width-- > 0)
			ft_putchar(' ');
		if (count)
			return (count);
		return (0);
	}
	str = (letter == 'x') ? ft_itoabaseu(nbr, 16, 1) : ft_itoabaseu(nbr, 16, 0);
	if (el->width)
		count = with_widthx(str, letter, el);
	else
		count = without_width(str, letter, el);
	if ((el->accuracy != -1) && ((size_t)el->accuracy > ft_strlen(str)))
		count += el->accuracy - ft_strlen(str);
	if (el->f_sharp && !(ft_strlen(str) == 1 && str[0] == '0'))
		count += 2;
	if ((size_t)el->width > ft_strlen(str) && el->accuracy < el->width)
		count = el->width;
	free(str);
	return (count);
}
