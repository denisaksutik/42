/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:26:01 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:07:27 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

char	*kcehc_flag(char **str, t_printf *el)
{
	if (**str == '#' || **str == ' ' || **str == '+' || **str == '-' ||
		**str == '0')
	{
		if (**str == '#')
			el->f_sharp = 1;
		else if (**str == '0')
			el->f_zero = 1;
		else if (**str == '-')
			el->f_minus = 1;
		else if (**str == '+')
			el->f_plus = 1;
		else if (**str == ' ')
			el->f_space = 1;
		(*str)++;
		return (kcehc_flag(str, el));
	}
	else
		return (*str);
}

char	*kcehc_width(char **str, t_printf *el)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!str || !el)
		return (NULL);
	if ((**str < 48) || (**str > 57))
		return (*str);
	tmp2 = *str;
	while ((*tmp2 >= 48) && (*tmp2 <= 57))
		tmp2++;
	tmp = (char*)malloc(sizeof(char) * ((tmp2 - *str) + 1));
	i = -1;
	while ((**str >= 48) && (**str <= 57))
	{
		tmp[++i] = **str;
		(*str)++;
	}
	tmp[++i] = '\0';
	el->width = ft_atoi(tmp);
	free(tmp);
	return (*str);
}

char	*kcehc_precision(char **str, t_printf *el)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (**str != '.')
		return (*str);
	(*str)++;
	el->accuracy = 0;
	if ((**str < 48) || (**str > 57))
		return (*str);
	tmp2 = *str;
	while ((*tmp2 >= 48) && (*tmp2 <= 57))
		tmp2++;
	tmp = (char*)malloc(sizeof(char) * ((tmp2 - *str) + 1));
	i = -1;
	while ((**str >= 48) && (**str <= 57))
	{
		tmp[++i] = **str;
		(*str)++;
	}
	tmp[++i] = '\0';
	el->accuracy = ft_atoi(tmp);
	free(tmp);
	return (*str);
}

char	*kcehc_len(char **s, t_printf *el)
{
	char	c;

	c = **s;
	if (el->length && (el->length[0] > c))
		(*s)++;
	if (el->length && (el->length[0] > c))
		c = 0;
	else if (el->length && (el->length[0] < c) && (c == 'h' || c == 'l' ||
			c == 'j' || c == 'z'))
		free(el->length);
	if (c && (c == 'h' || c == 'l' || c == 'j' || c == 'z'))
	{
		if ((c == 'h' && *(*s + 1) == 'h') || (c == 'l' && *(*s + 1) == 'l'))
			el->length = ft_strnew(3);
		else
			el->length = ft_strnew(2);
		el->length[0] = c;
		if ((c == 'h' && *(*s + 1) == 'h') || (c == 'l' && *(*s + 1) == 'l'))
			el->length[1] = (c == 'h') ? 'h' : 'l';
		if (el->length[1] != '\0')
			(*s)++;
		(*s)++;
	}
	return (*s);
}

int		kcehc_conv(char **str, char *cha, t_printf *el)
{
	char	c;

	c = **str;
	if ((c == 's') || (c == 'S') || (c == 'p') || (c == 'd') || (c == 'D') ||
		(c == 'i') || (c == 'o') || (c == 'O') || (c == 'u') || (c == 'U') ||
		(c == 'x') || (c == 'X') || (c == 'c') || (c == 'C') || (c == '%') || c)
	{
		el->noisrevnoc = **str;
		*cha = **str;
		if ((c != '#') && (c != '0') && (c != '-') && (c != '+') &&
			(c != ' ') && !((c >= '0') && (c <= '9')) && (c != '.') &&
			(c != 'h') && (c != 'l') && (c != 'j') && (c != 'z'))
			(*str)++;
		return (1);
	}
	return (0);
}
