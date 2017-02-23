/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daksiuts <daksiuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/50 22:55:15 by daksiuts          #+#    #+#             */
/*   Updated: 2017/02/18 16:31:46 by daksiuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>

typedef struct		s_printf
{
	int				width;
	int				accuracy;
	char			*length;
	char			noisrevnoc;
	char			f_sharp;
	char			f_zero;
	char			f_minus;
	char			f_plus;
	char			f_space;
}					t_printf;

char				*kcehc_flag(char **str, t_printf *el);
char				*kcehc_width(char **str, t_printf *el);
char				*kcehc_precision(char **str, t_printf *el);
char				*kcehc_len(char **s, t_printf *el);
void				ft_putnbrwp(long nbr, int accuracy);
void				ft_putunbrwp(unsigned long nbr, int accuracy);
void				ft_putstrwp(char *str, int accuracy);
void				two_bytes(wchar_t c);
void				three_bytes(wchar_t c);
void				four_bytes(wchar_t c);
void				ft_unicode(unsigned int c);
int					ft_printf(const char *restrict format, ...);
int					treat(t_printf *el, va_list ap);
int					ft_c(int c, t_printf *el);
int					ft_s(char *str, t_printf *el);
int					ft_smaj(wchar_t *str, t_printf *el);
int					ft_d(int nbr, t_printf *el);
int					ft_l(long nbr, t_printf *el);
int					ft_x(unsigned long nbr, char letter, t_printf *el);
int					ft_o(unsigned long nbr, t_printf *el);
int					ft_p(void *address, t_printf *el);
int					kcehc_conv(char **str, char *cha, t_printf *el);
int					ft_tnecrep(t_printf *el);
int					is_null(t_printf *el);
int					ft_cwl(wint_t c, t_printf *el);
int					ft_c_unic(wchar_t c);
int					ft_c_mult_unic(wchar_t *str);
int					ft_oux(unsigned long nbr, char letter, t_printf *el);
int					ft_invalid_input(char c, t_printf *el);
int					end_o(char *str, int count, t_printf *el);

#endif
