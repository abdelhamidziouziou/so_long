# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 02:51:05 by abziouzi          #+#    #+#              #
#    Updated: 2022/04/26 01:27:11 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = src/so_long.c \
		src/so_long_utils.c \
		ft_printf/libftprintf.a


OBJECTS = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJECTS)
	ar rcs $(NAME) $?
	$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(make) ft_printf/

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
