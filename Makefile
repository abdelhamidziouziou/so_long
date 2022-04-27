# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:49:21 by abziouzi          #+#    #+#              #
#    Updated: 2022/04/27 20:55:19 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/so_long.c src/so_long_utils.c src/get_next_line.c src/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
