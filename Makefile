# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:49:21 by abziouzi          #+#    #+#              #
#    Updated: 2022/06/02 18:07:22 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

C_FLAGS = -Wall -Wextra -Werror -c

SRC =	so_long.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $?
			$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
			$(CC) $(C_FLAGS) -Imlx $< -o $@

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean reß
