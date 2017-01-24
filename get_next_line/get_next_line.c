/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:24:16 by daksiuts          #+#    #+#             */
/*   Updated: 2017/01/11 20:24:35 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list			*get_file(t_list **text, int fd)
{
	t_list				*tmp;

	tmp = *text;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(text, tmp);
	tmp = *text;
	return (tmp);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_list		*text;
	int					i;
	int					ret_val;
	t_list				*div;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	div = get_file(&text, fd);
	CHECKING((*line = ft_strnew(1)));
	while ((ret_val = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret_val] = '\0';
		CHECKING((div->content = ft_strjoin(div->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret_val < BUFF_SIZE && !ft_strlen(div->content))
		return (0);
	i = ft_stop_copy(line, div->content, '\n');
	(i < (int)ft_strlen(div->content))
		? div->content += (i + 1)
		: ft_str_s_clr(div->content);
	return (1);
}
