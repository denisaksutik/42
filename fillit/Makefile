# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daksiuts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 19:51:16 by daksiuts          #+#    #+#              #
#    Updated: 2016/12/19 17:02:03 by vbut             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =	main.c \
		testing.c \
		large.c \
		file_reader.c \
		check_map.c \
		solution_tetr.c

OBJ = $(SRC:.c=.o)

.PHONY: fclean all re clean

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
