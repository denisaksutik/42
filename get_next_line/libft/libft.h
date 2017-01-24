/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:58:56 by daksiuts          #+#    #+#             */
/*   Updated: 2017/01/11 20:44:20 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);
void				ft_str_s_clr(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
int					ft_stop_copy(char **dst, char *src, char c);
void				ft_bzero(void *s, size_t n);
char				*ft_strjoinchar(char const *s1, char c);
void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif
