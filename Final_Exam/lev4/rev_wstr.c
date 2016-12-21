/*le  ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:29:30 by daksiuts          #+#    #+#             */
/*   Updated: 2016/12/04 13:41:28 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int rev_wstr(const char *str, int len)
{
	int	i;

	i = 0;
	while ((len > 0) && (str[len] == ' ' || str[len] == '\t'))
		len--;
	while (i <= len && (str[len - i] != ' ' && str[len - i] != '\t'))
		i++;
	write(1, str + len - i + 1, i);
	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	if (i < len)
		write(1, " ", 1);
	return (len - i);
}

int main(int ac, char **av)
{
	int len;

	len = 0;
	if (ac == 2)
	{
		while (av[1][len] != '\0')
			len++;
		len--;
		while (len > 0)
			len = rev_wstr(av[1], len);
	}
	write(1, "\n", 1);
	return (0);
}
