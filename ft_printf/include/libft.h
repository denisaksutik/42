/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:09:28 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:30:07 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_puttabstr(char **str);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstaddmid(t_list **alst, t_list *previous, t_list *new);
void				ft_bzero(void *s, size_t n);
void				ft_putnstr(char *str, int nbr);
void				ft_putwchar(wchar_t c);
void				ft_putzerox(char letter);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
short				ft_countnbr(long nbr);
short				ft_countunbr(unsigned long nbr);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_lstcount(t_list **lst);
size_t				ft_strlen(char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(long n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoabase(long nbr, int base, char min);
char				*ft_itoabaseu(unsigned long nbr, int base, char min);
void				*ft_memset (void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memtaballoc(size_t tab, size_t size);
char				*ft_strrev(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**ft_strsplit(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
void				ft_putunbr(unsigned long n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
