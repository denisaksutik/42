/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 11:14:19 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/12 18:14:57 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define ABS(v) ((v) < 0 ? -(v) : (v))

void	fun(int n, int b, char *s, int *p)
{
	char base[] = "0123456789ABCDEF";

	if (n <= -b || b <= n)
		fun(n / b, b, s, p);
	s[(*p)++] = base[ABS(n % b)];
}

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	int		p;

	if (base < 2 || 16 < base
			|| !(s = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		s[p++] = '-';
	fun(value, base, s, &p);
	s[p] = '\0';
	return (s);
}
