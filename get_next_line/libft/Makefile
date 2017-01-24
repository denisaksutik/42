# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 15:18:54 by daksiuts          #+#    #+#              #
#    Updated: 2016/11/24 17:04:57 by daksiuts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

FLAG	= -c -Wall -Wextra -Werror

SRC		= ft_strlen.c ft_strchr.c ft_strnew.c ft_str_s_clr.c ft_strjoin.c \
		  ft_lstnew.c ft_lstadd.c ft_stop_copy.c ft_bzero.c \
		  ft_strjoinchar.c ft_memcpy.c

OBJ		= $(SRC:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
