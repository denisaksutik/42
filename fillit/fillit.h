/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbut <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:41:08 by vbut              #+#    #+#             */
/*   Updated: 2016/12/20 19:41:12 by vbut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_dot
{
	int				x;
	int				y;
}					t_dot;

typedef struct		s_tetr
{
	t_dot			body[4];
	t_dot			pos;
	struct s_tetr	*next;
	char			c;
}					t_tetr;

static const t_dot	g_tetr[19][4] = {
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 3, .y = 0}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 0, .y = 2}, {.x = 0, .y = 3}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 0, .y = 2}, {.x = 1, .y = 2}},
	{{.x = 1, .y = 0}, {.x = 1, .y = 1}, {.x = 0, .y = 2}, {.x = 1, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 0, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 1, .y = 1}, {.x = 1, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 2, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 0, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 2, .y = 1}},
	{{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 1, .y = 2}},
	{{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 0, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 1, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 1, .y = 2}},
	{{.x = 1, .y = 0}, {.x = 2, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}},
	{{.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}, {.x = 0, .y = 2}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 1, .y = 1}, {.x = 2, .y = 1}},
	{{.x = 0, .y = 0}, {.x = 1, .y = 0}, {.x = 0, .y = 1}, {.x = 1, .y = 1}}
};

int					square_min(t_tetr	*tetr);
void				clean_tetr(t_tetr *tetr, char **dot);
char				**g_new_map(int size);
char				*ft_strnew(size_t size);
void				map_free(char **map);
int					file_reader(int a, t_tetr *tetr);
void				s_tetr(char *point, t_tetr *tetr);
void				position(t_tetr *tetr, int i, int x, int y);
int					large_ln(t_tetr *tetr);
int					large_x(t_tetr *tetr);
int					large_y(t_tetr *tetr);
t_tetr				*tetr_place(void);
void				map_print(char **map);
int					output(int code);
char				**solution_tetr(t_tetr *tetr);
int					write_tetr(t_tetr *q, char **c, int small);
int					next_s(t_tetr *tetr, int small, char **c);
int					move_tetr(int small, t_tetr *tetr);
void				b_tetr(t_tetr *tetr);
void				testing(t_tetr *tetr);
int					compare_tetr(t_tetr *tetr);

#endif
